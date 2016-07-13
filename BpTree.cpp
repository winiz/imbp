#include<iostream>
#include <cstddef>
#include "BpTree.h"
using namespace std;
 
// Constructor for BTreeNode class
BTreeNode::BTreeNode(int _n, bool _leaf){
    // Copy down the given maximum number of search key value
    n = _n;
    // Allocate memory for maximum number of possible keys
    keys = new int[n];
    // Copy down the leaf property
    leaf = _leaf;
    // allocate child pointers
    C = new BTreeNode *[n+1];
    // Initialize the current number of keys as 0
    ck = 0;
}

//TESTING PURPOSES
int BTreeNode::prints(){
    return n;  
}
// Function to traverse all nodes in a subtree rooted with this node
void BTreeNode::traverse(){}
 
// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::search(int k){}


// Constructor for BpTree (Initializes tree as empty)
BpTree::BpTree(int _n){  
    root = NULL;  
    n = _n;
}

// Function to traverse the tree
void BpTree::traverse(){
    if (root != NULL) root->traverse(); 
}
 
// Function to search a key in this tree
BTreeNode* BpTree::search(int k){  
    return (root == NULL)? NULL : root->search(k); 
}