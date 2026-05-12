//
//  activity_bst.h
//  ekiziloglu_kiziloglu_eralp_4
//
//  Created by Eralp  Kızıloğlu on 29.11.2022.
//

#ifndef activity_bst_h
#define activity_bst_h

#include <string>
using namespace std;



struct tree_node {
   int time;
   string activity;
   tree_node *right;
   tree_node *left;
   tree_node *parent; //if a node does not have a parent it should point to nullptr
   tree_node(int t, const string &a) : time(t), activity(a),right(nullptr), left(nullptr),parent(nullptr) {}
};

class ActivityBST{
    
private:
    tree_node * root;
    
    
    
public:
    ActivityBST(); //default constructor
    ~ActivityBST(); //destructor
    ActivityBST (const ActivityBST &);  //copy constructor
    void add(int time, const string & activity);
    const ActivityBST & operator=(const ActivityBST & rhs);
    ActivityBST operator+(const ActivityBST & rhs)const;
    ActivityBST operator+=(const ActivityBST & rhs)const;
    
    
    
    
};

//where do I define free function

#endif /* activity_bst_h */
