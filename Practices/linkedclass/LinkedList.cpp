#include "LinkedList.h"

LinkedList::LinkedList(){
    size = 0;
    head = NULL;
    tail = NULL;
}

void LinkedList::add_to_end(int val){
    if(isEmpty()){
        head = new Node(val);
        tail = head;
    }
    else{
        tail->next = new Node(val);
        tail = tail->next;
    }
    size++;
}

void LinkedList::add_to_beginning(int val){
    if(isEmpty()){
        head = new Node(val);
        tail = head;
    }
    else{
        Node* temp = new Node(val, head);
        head = temp;
    }
    size++;
}


LinkedList::LinkedList(int* arr, int len){ // converts dynamic int array to linkedlist
    size = 0;
    head = NULL;
    tail = NULL;

    for(int i=0; i<len; i++){
        // arr[i]
        add_to_end(arr[i]);
    }

    /*
    for(int i=size-1; i>=0; i--){
        // arr[i]
        add_to_beginning(arr[i]);
    }
    */
}

bool LinkedList::isEmpty()const{ return head == NULL;}


// vec[0] = 10;

int & LinkedList::operator[](int index)const{ // list[5] = 10;
    int i = 0;
    Node* temp = head;
    while(i < index){
        temp = temp->next;
        i++;
    }
    return temp->val;
}
// list[10] = 20;


Node* LinkedList::find_ith(int index){
    int i = 0;
    Node* temp = head;
    while(i < index){
        temp = temp->next;
        i++;
    }
    return temp;

}


void LinkedList::delete_ind(int index){
    if(index == 0){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    else{
        Node* temp = find_ith(index -1);
        Node* to_be_deleted = temp -> next;
        temp->next = temp->next->next; 
        delete to_be_deleted;
    }

}

LinkedList::LinkedList(const LinkedList & copy){
    head = NULL;
    tail = NULL;
    size = 0;
    Node* temp = copy.head;
    while(temp){
        add_to_end(temp->val);
        temp = temp->next;
    }
}


void LinkedList::clear(Node* node){
    Node *temp = node;
    Node* current = NULL;
    while(temp){
        current = temp;
        temp = temp->next;
        delete current;
    }
}

/*
*(this->head): node objesi
*this: linkedlist objesi
this: linkedlist pointeri
this->head: node pointeri
*/
LinkedList::~LinkedList(){
    clear(head);
}
// A = B
// A = B = C
const LinkedList & LinkedList::operator=(const LinkedList & rhs){
    if(this != &rhs){ // A = B
        if(size == rhs.size){
            for(int i=0; i<size; i++){
                (*this)[i] = rhs[i];
            }
        }
        else{
            clear(head);
            head = NULL;
            tail = NULL;
            size = 0;
            Node* temp = rhs.head;
            while(temp){
                add_to_end(temp->val);
                temp = temp->next;
            }
        }
    }
    return *this;
}


LinkedList LinkedList::operator+(const LinkedList & rhs)const{
    LinkedList result(*this);
    Node * temp = rhs.head;
    while(temp){
        result.add_to_end(temp->val);
        temp = temp->next;
    }
    return result;
}

const LinkedList & LinkedList::operator*=(const LinkedList & rhs){
    for(int i=0; i<size; i++){
        (*this)[i] = (*this)[i] * rhs[i];
    }
    return *this;
}


bool LinkedList::operator==(const LinkedList & rhs) const{
    for(int i =0; i<size; i++){
        if((*this)[i] != rhs[i]){
            return false;
        }
    }
    return true;
}

bool LinkedList::operator!=(const LinkedList & rhs) const{
    return !((*this) == rhs);
}
