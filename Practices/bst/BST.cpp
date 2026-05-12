//
//  BST.cpp
//  cs204BST
//
//  Created by Eralp  Kızıloğlu on 19.11.2022.
//

#include "BST.hpp"
#include <iostream>
#include <cstdlib>

using namespace std;



BST::BST(){ //constructor
    root = NULL;
    
    
}
BST::node* BST::createLeaf(int key){//we need to say BST since we are using it from the class

    node * n = new node;
    n->key = key;  //first key is what is inside node and second key is the passed parameter value
    n->left = NULL;
    n->right = NULL;
    
    return n;
    
}


void BST::AddLeaf(int key){
    AddLeafPrivate(key,root);
    
}


void BST::AddLeafPrivate(int key,node * Ptr){
    if(root == NULL){
        root = createLeaf(key);
    }
    
    else if(key < Ptr->key){
        if(Ptr->left != NULL){
            AddLeafPrivate(key, Ptr->left);
        }
        else {
            Ptr->left = createLeaf(key);
        }
    }
    
    else if(key > Ptr->key){
        if(Ptr->right != NULL){
            AddLeafPrivate(key, Ptr->right);
        }
        else {
            Ptr->right = createLeaf(key);
        }
    }
    
    else{
        
        cout<<"The key: "<<key<<" has already been added to the tree"<<endl;
    }
    
    
    
    
}
