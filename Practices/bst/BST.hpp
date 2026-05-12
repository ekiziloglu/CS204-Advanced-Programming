//
//  BST.hpp
//  cs204BST
//
//  Created by Eralp  Kızıloğlu on 19.11.2022.
//

#ifndef BST_hpp
#define BST_hpp

#include <stdio.h>



class BST
{
private:
    struct node{
        int key;
        node *left;
        node *right;
        
    };
    
    node *root;
    
    void AddLeafPrivate(int key,node * Ptr);
    
    
    
public:
    BST();
    node* createLeaf(int key);
    void AddLeaf(int key);
    
    
};

#endif /* BST_hpp */
