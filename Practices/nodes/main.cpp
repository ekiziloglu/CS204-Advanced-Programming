//
//  main.cpp
//  cs204NODES
//
//  Created by Eralp  Kızıloğlu on 18.11.2022.
//

#include <iostream>

#include <string>

using namespace std;

struct node {
  int info;
  node *next;
  
  node ()
  {}

  node (const int & s, node * link)
    : info(s), next (link)
  {}
};

node* Add2End(node * tail, int id)
{
  node *nn = new node(id,nullptr);
  tail->next = nn;
  return nn;

  //This added the new id to the end of the list,
  //but now tail also needs updating ñ how?
  //we could return the new tail from the function: node * Add2End(node * tail, int id)
  //and let the caller do the update
  //or we could make tail a reference parameter and update it hereÖ
}


void DisplayList (node * head)
{
  cout << "The list content is: ";
  node * ptr = head;
  while(ptr) //  while (ptr != nullptr)
    {
      cout << ptr ->info << " ";
      ptr = ptr->next;
    }
  cout << endl<<endl;
}

node * AddInOrder(node * head, int newkey)
// pre: list is sorted
// post: add newkey to list, keep list sorted, return head of new list with newkey in it
{
  node *  ptr = head;   // loop variable
  
  // if new node should be first, handle this case and return
  // in this case, we return the address of new node since it is new head
  if (head == nullptr || newkey < head->info)
    {
      node * temp = new node;  //node to be inserted
      temp->info = newkey;
      temp->next = head; //connect the rest
      return temp;
      //return new node(newkey, head);    //alternative to prev. 4 lines
    }
  
  // check node one ahead so we don't pass!
  while (ptr->next != nullptr && ptr->next->info < newkey)
    {
      ptr = ptr->next;
    } // postcondition: new node to be inserted just after the node that ptr points
  
  //now insert node with newkey after where ptr points to
  node * temp = new node;  //node to be inserted
  temp->info = newkey;
  temp->next = ptr->next; //connect the rest
  ptr->next = temp;
  //ptr->next = new node(newkey,ptr->next);   //alternative to prev. 4 lines
  
  return head;
}

node * AddInOrder2(node * head, int newkey)
// pre: list is sorted
// post: add newkey to list, keep list sorted, return head of new list with newkey in it
{
  node *  ptr = head;   // loop variable
  
  // if new node should be first, handle this case and return
  // in this case, we return the address of new node since it is new head
  if (head == nullptr || newkey < head->info)
    {
      return new node(newkey, head);
    }
  
  node * prev; //to point to the previous node
  while (ptr != nullptr && ptr->info < newkey)
    {
      prev = ptr;     //hold onto previous node so we do not pass too far
      ptr = ptr->next;
    } // postcondition: new node to be inserted between prev and ptr
  
  //now insert node with newkey
  prev->next = new node(newkey,ptr);
  
  return head;
}

/* This function (AddInOrderRecursive) is no longer explained in the lectures.
   You can have a look at that if interested */
/*node * AddInOrderRecursive(node * head, int newkey)
// pre: list is sorted
// post: add newkey to list, keep list sorted, return head of new list with newkey in it
{
    //base condition of the recursion
    if (head == nullptr || newkey < head->info)
        return new node(newkey, head);

    head->next = AddInOrderRecursive (head->next, newkey);  //recursive call
    return head;
}*/

void DeleteOneNode (node * toBeDeleted, node * & head)
/* pre: toBeDeleted points to the node to be deleted from the list
   post: deletes the node pointed by toBeDeleted, updates head if changes */
{
    node * ptr;
        
    if (toBeDeleted == head)  //if the node to be deleted is the first node
    {
        head = head->next;
        delete toBeDeleted;
    }
    else  //if the node to be deleted is in the middle or at the end
    {
        ptr = head;
        while (ptr->next != toBeDeleted)
            ptr = ptr->next;
        //after while ptr point to the node just before toBeDeleted

        //connect the previous node to the next node and delete
        ptr->next = toBeDeleted->next;
        delete toBeDeleted;
    }
}



int countCircular (node * last)
//pre: list is a circularly linked one, last points to the last node
//post: returns number of nodes in the list
{
    if (last == nullptr)
        return 0; //list is empty
    
    int count = 0;
    node * ptr = last;
    do {
        count++;
        ptr = ptr->next; //advance to the next line
    } while (ptr != last); //loop until you reach where you started
    return count;
}


int main(){
    int storage[] = {8,6,4,2};
    node *tail, *head = nullptr;
    node *temp = nullptr;
    
    for (int k=0; k < 4; k++)  {
      temp = new node();
      temp->info = storage[k];
      temp->next = head;
      head = temp;
    }
    
    DisplayList (head);
    
    
    
    
    return 0;
}
