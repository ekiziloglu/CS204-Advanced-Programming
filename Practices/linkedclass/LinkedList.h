#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

struct Node{
    int val;
    Node * next;
    Node(int v = -1, Node* n = NULL):val(v), next(n){}
};

class LinkedList{

public:
    LinkedList();
    LinkedList(int* arr, int size);
    LinkedList(const LinkedList & copy); // deep copy
    bool isEmpty()const;
    ~LinkedList(); // destructor
    void add_to_end(int val);
    void add_to_beginning(int val);
    int & operator[](int index)const; // list[i] -> returns ith element of list as a reference
    void delete_ind(int index);
    const LinkedList & operator=(const LinkedList & rhs); // A = (B = C)
    LinkedList operator+(const LinkedList & rhs)const; // concatenates two lists
    const LinkedList & operator*=(const LinkedList & rhs); // elewise multiplication
    bool operator==(const LinkedList & rhs) const;
    bool operator!=(const LinkedList & rhs) const;
    int getSize()const { return size;}
    friend LinkedList operator*(const LinkedList & lhs, const LinkedList & rhs);

private:

    Node* find_ith(int index);
    void clear(Node* node);
    Node* head;
    Node* tail;
    int size;
};

#endif