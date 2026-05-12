#include "activity_bst.h"
#include <string>
#include <iostream>

using namespace std;

const string ACTIVITY_CHECK_ERROR = "ERROR! Could not print activity at specific time due to illegal time\n";

inline string fill_with_zeros(int num_zeros, const string &input) {
    int zeros_to_add = num_zeros - input.length();
    if (zeros_to_add < 0) zeros_to_add = 0;
    return string(zeros_to_add, '0') + input;
}

inline string number_to_time(int number) {
    if (number > 2359 || number < 0) return "ERROR";
    return fill_with_zeros(2, to_string(number / 100)) + ":" +
           fill_with_zeros(2, to_string(number % 100));
}

string add_activity_internal(tree_node *&root, int time, const string &activity);

tree_node *get_successor_internal(tree_node *curr);

tree_node *get_target_node_internal(tree_node *root, int target_time);

string get_single_activity_internal(tree_node * root, const string &activity);

string get_activity_internal(tree_node* root, int time);

void print_all_activities_helper(tree_node *curr);

void print_single_activity_helper(tree_node *curr, const string &activity);

string get_activity_and_duration_internal(tree_node *&root, int target_time);

string get_all_activities_internal(tree_node* root);

// Check if the time represented by the integer `time` is legal
inline bool legal_time(int time) {
    if (time > 2359 || time < 0)
        return false;
    if (time % 100 > 59 || time / 100 > 23)
        return false;
    return true;
}

//! Finds the activity in which `target_time` falls and returns a pointer to its tree_node.
/*!
 * Searches for the node with the largest `time` that is smaller than `target_time` and
 * returns a pointer to it.
 * @param root a pointer at the root of an activity bst.
 * @param target_time the time point being checked.
 * @return A pointer at the node containing the activity in which `target_time` falls.
 * Returns nullptr if the tree is empty or if `target_time` falls before all the tree's activity.
 */
tree_node *get_target_node_internal(tree_node *root, int target_time) {
    tree_node *target;
    if (root == nullptr) return nullptr;
    tree_node *curr = root;
    bool found = false;
    while (!found) {
        if (curr->time == target_time) {
            target = curr;
            found = true;
        } else {
            // if curr->time < target_time, either return `curr`
            // or move to the next node after `curr` in sorted order
            if (curr->time < target_time) {
                // If we sort the nodes based on time, `successor` would be
                // the one the comes right after `curr`
                tree_node *successor = get_successor_internal(curr);
                // If `curr` is the last node in the tree, or
                // successor->time > target_time, `curr` is our target
                if (successor == nullptr || successor->time > target_time) {
                    target = curr;
                    found = true;
                }
                    // If the successor of `curr` has a time value that is smaller than
                    // `target_time`, then `curr` isn't our target, we need to check the
                    // next node in the tree
                else {
                    curr = curr->right;
                }
            }
                // If `curr->time > target_time`
            else {
                // If there are no nodes with a smaller `target_time` value than `curr`,
                // then `target_time` is before every activity in the tree
                if (curr->left == nullptr) {
                    target = nullptr;
                    found = true;
                }
                    // If there are still nodes in the tree with smaller target_time
                    // than curr->target_time
                else {
                    curr = curr->left;
                }
            }
        }
    }
    return target;
}

//! Returns a pointer at the node that comes right after `curr` in an in-order traversal
/*!
 * If we sort all the nodes of the tree based on their time values into a list,
 * then this function will return a pointer at the node right after `curr` in this
 * list.
 * @param curr a pointer at a node in an activity bst.
 * @return a pointer at the next node after `curr` in an in-order traversal.
 * Returns nullptr if `curr` is the last node in the tree or if curr is nullptr.
 */
tree_node *get_successor_internal(tree_node *curr) {
    tree_node* successor;
    if (curr == nullptr) successor = nullptr;
        // If the node has right children, the successor is going to be the smallest
        // node in the subtree rooted at `curr->right`
    else if (curr->right != nullptr) {
        // Find the smallest node in the subtree with root `curr->right`
        tree_node *tmp = curr->right;
        while (tmp->left != nullptr) tmp = tmp->left;
        successor = tmp;
    }
        // If the node doesn't have a right child, it means we have to go up to find the successor
    else {
        // If the node doesn't have a parent (is the root of a tree) and doesn't have
        // right children, then it's the biggest node with no successor
        if (curr->parent == nullptr) return nullptr;
            // If the node is a left child, then it's parent is the next biggest node after it
        else if (curr->parent->left == curr) {
            successor = curr->parent;
        }
            // If the node is a right parent, then its parent is smaller than it. We need to find
            // the first ancestor of the node who is a left child. The parent of that node will
            // be the successor.
        else {
            tree_node *tmp = curr->parent;
            // Find the first ancestor who is a left child
            while (tmp->parent != nullptr && tmp->parent->right == tmp) {
                tmp = tmp->parent;
            }
            // If we couldn't find an ancestor who is a left child, then `curr` is the biggest
            // node in the tree
            if (tmp->parent == nullptr) successor = nullptr;
            else successor = tmp->parent;
        }
    }
    return successor;
}

//! Add an activity to the activity bst and returns the output message.
/*!
 * Add a node to the activity bst. This function assumes that the there are
 * no nodes with the same time value already added to the tree. If the passed
 * `target_time` is illegal, no new nodes are added.
 * @param root a pointer at the root of the activity bst to which
 * the node is going to be added.
 * @param time The time of the new node.
 * @param activity The activity name of the new node.
 * @return a string message detailing the time and name of added activity or an error
 * message if the time was illegal.
 */
string add_activity_internal(tree_node *&root, int time, const string &activity) {
    string output;
    if (!legal_time(time)) {

        output = "ERROR! Could not add activity '" + activity
                 + "' due to illegal time value\n";
    }
    else {
        if (root == nullptr) {
            root = new tree_node(time, activity);
        } else {
            tree_node *curr = root;
            tree_node *new_node;
            new_node = new tree_node(time, activity);
            bool added = false;
            while (!added) {
                if (curr->time == time){
                    curr->activity = activity;
                    added = true;
                    delete new_node;
                }
                else if (curr->time > time) {
                    if (curr->left == nullptr) {
                        new_node->parent = curr;
                        curr->left = new_node;
                        added = true;
                    } else {
                        curr = curr->left;
                    }
                } else if (curr->time < time) {
                    if (curr->right == nullptr) {
                        new_node->parent = curr;
                        curr->right = new_node;
                        added = true;
                    } else {
                        curr = curr->right;
                    }
                }
            }
        }
        output = "Added activity '" + activity + "' at " + number_to_time(time) + '\n';
    }
    return output;
}

//! Add an activity to the activity bst and print the addition message to standard output
void add_activity(tree_node*& root, int time, const string& activity){
    cout << add_activity_internal(root, time, activity);
}

//! For a given target time, find which activity is taking place and its duration.
/*!
 * Given some `target_time`, will find the activity that will be taking place
 * at that specific time.
 * @param root root of the activity bst.
 * @param target_time time to search for.
 * @return A string containing the duration and name of the event taking place
 * at `target_time`. If `target_time` comes before the first event in
 * the activity bst, will return "free" with the duration
 * 00:00 - <time of first event or 00:00 if tree is empty. Returns an error
 * string if the passed time is illegal.
 */
string get_activity_and_duration_internal(tree_node *&root, int target_time) {
    if (!legal_time(target_time)) {
        return ACTIVITY_CHECK_ERROR;
    }
    // Get the node in which `target_time` falls
    tree_node *target = get_target_node_internal(root, target_time);
    string output = "Time period: ";
    // If this time is before the start of any other activity,
    // then it falls in the free time before events
    if (target == nullptr) {
        tree_node *start = root;
        int actual_time;
        // If there are no activities in the tree yet,
        // then free will last until 00:00
        if (start == nullptr) actual_time = 0;
            // If not, then find the start time of the first
            // task in the day.
        else {
            while (start->left != nullptr) start = start->left;
            actual_time = start->time;
        }
        output += "[00:00 - " + number_to_time(actual_time) + "]: free";
    }
        // If there is an activity taking place at time `target_time`
    else {
        // Find the next activity after `target`
        tree_node *successor = get_successor_internal(target);
        int next_val = 0;
        // If there is a next activity, its start is the end time
        // of this activity. Otherwise, the end time of this activity
        // is 00:00 (next day)
        if (successor != nullptr) next_val = successor->time;
        output += "[" + number_to_time(target->time) + " - " +
                  number_to_time(next_val) + "]: " + target->activity;
    }
    return output;
}

//! Prints the duration and name of the activity taking place at `time`.
/*!
 * Prints the duration and name of activity taking place at `time`
 * to standard output. If the time is illegal prints an error message.
 * @param root root of the activity bst.
 * @param time time to check in the tree.
 */
void print_activity_and_duration(tree_node *root, int time) {
    cout << get_activity_and_duration_internal(root, time) << endl;
}

//! Adds to the `output` string all the durations of `activity` in the tree rooted at `curr`.
/*!
 * Given the activity bst with root `curr`, will add the durations of
 * `activity` in all of the nodes in this tree in chronological order to the `output` string.
 * Specifically, it does an in-order traversal of the nodes of tree. At each node, if its
 * activity is `activity`, add its period to the output string
 * @param curr the root of the tree in which the search for `activity` happens.
 * @param activity the name of the activity to search for.
 * @param output the output string containing all the durations.
 */
void get_single_activity_internal_helper(tree_node *curr, const string &activity, string& output) {
    if (curr == nullptr) return;
    // Add the occurrences of `activity` in the left subtree of `curr`
    // to the output string
    get_single_activity_internal_helper(curr->left, activity, output);
    // if `curr` has the desired activity, add the activity and duration
    // at `curr` to the output string
    if (curr->activity == activity) {
        // This will add the duration of the activity of `curr`
        output += get_activity_and_duration_internal(curr, curr->time) + '\n';
    }
    // Add the occurrences of `activity` in the right subtree of `curr`
    // to the output string
    get_single_activity_internal_helper(curr->right, activity, output);
}

//! Returns a string with the durations of all occurrences of `activity` in a binary bst.
/*!
 * Returns a string containing all the durations of the activity `activity` occurring in the
 * activity bst in chronological order. If `activity` is "free", will also check if there is
 * any free time before any activities in the day and will return this free duration.
 * @param root root of the activity bst.
 * @param activity the name of the activity whose durations are needed.
 * @return A string containing the durations of `activity` seperated by an end lines. If
 * `activity` never occurs in the tree, returns an empty string.
 */
string get_single_activity_internal(tree_node * root, const string &activity){
    string output;
    if (activity == "free") {
        // tree is empty -> entire day is free
        if (root == nullptr){
            output+= "Time period: [00:00 - " +number_to_time(0)
                     + "]: free\n";
        } else {
            int earliest_time;
            // Go to the node with the smallest time in the tree
            tree_node * tmp = root;
            while (tmp->left != nullptr) tmp = tmp->left;
            earliest_time = tmp->time;
            // If the earliest event time is not zero, it means there is a period of time
            // before the first event that is "free"
            if (earliest_time != 0){
                output+= "Time period: [00:00 - " + number_to_time(earliest_time) + "]: free\n";
            }
            // else, the first event of the day starts at time 00:00 and there are no earlier events
            // -> we don't need to print a free event at the beginning of the day
        }
    }
    get_single_activity_internal_helper(root, activity, output);
    return output;
}

//! Print the all the durations of `activity` in the activity bst to standard output.
/*!
 * Prints a string containing all the durations of `activity` seperated by end lines
 * to standard output.
 * @param root root of the activity bst.
 * @param activity the name of the activity.
 */
void print_single_activity(tree_node *root, const string &activity) {
    cout << get_single_activity_internal(root, activity);
}

//! Gets the name of the activity taking place at `time`.
/*!
 * Get the activity taking place at some time point.
 * @param root root of the activity bst.
 * @param time the time point being searched for.
 * @return A string containing the time and the name of the activity.
 * If the time value is illegal, returns an error.
 */
string get_activity_internal(tree_node* root, int time){
    string output;
    if (!legal_time(time)) {
        output = ACTIVITY_CHECK_ERROR;
    } else{
        tree_node *target = get_target_node_internal(root, time);
        output+= "Time: " + number_to_time(time) + ", Activity: ";
        if (target == nullptr) output+= "free";
        else output+= target->activity;
        output+= '\n';
    }
    return output;
}

//! Prints the activity taking place at `time` to standard output.
/*!
 * Prints a string containing the name of the activity taking place
 * at `time`. If `time` is illegal, prints an error message instead.
 * @param root root of the activity bst.
 * @param time time to search for.
 */
void print_activity(tree_node *root, int time) {
    cout << get_activity_internal(root, time);
}

//! Adds to `output` the name and start times of all activities in the tree.
/*!
 * Does an in-order traversal of all the nodes in the tree with root `curr`
 * and adds the names and start times of all its activities to the output string.
 * @param curr the root of the activity bst.
 * @param output the string containing the names and start times of all activities.
 */
void get_all_activities_internal_helper(tree_node *curr, string& output) {
    if (curr == nullptr) return;
    // Add to `output` the names and start times of all activities in the
    // left subtree of `curr`, i.e., that are before `curr`
    get_all_activities_internal_helper(curr->left, output);
    // Add to `output` the name and start time of the activity in `curr`
    output+= "[" + number_to_time(curr->time) + "] - " + curr->activity
             + '\n';
    // Add to `output` the names and start times of all activities in the
    // right subtree of `curr`, i.e., that are after `curr`
    get_all_activities_internal_helper(curr->right, output);
}

//! Get a string with the start times and names of all the activities in the tree.
/*!
 * Get a string containing all the names and start times of the tree with root `root`
 * seperated by end lines.
 * @param root the root of the activity bst.
 * @return A string containing the names and start times of all the events in the
 * activity bst seperated by end lines.
 */
string get_all_activities_internal(tree_node* root){
    string output;
    get_all_activities_internal_helper(root, output);
    return output;
}

//! Prints a string with start times and names of all the activities to standard output.
/*!
 * Prints a string of the time and name of every activity in the tree with root `root`
 * to the standard output. If there are no activities in the tree prints nothing.
 * @param root the root of the activity bst
 */
void print_all_activities(tree_node *root) {
    cout << get_all_activities_internal(root);
}

//! Deletes the activity bst rooted at `root`.
/*!
 * Deletes the activity bst rooted at `root` using a post-order
 * traversal.
 * @param root
 */
void delete_tree(tree_node *root) {
    if (root == nullptr) return;
    // Delete the nodes in the left subtree
    delete_tree(root->left);
    // Delete the nodes in the right subtree
    delete_tree(root->right);
    // Delete `root`
    delete root;
}