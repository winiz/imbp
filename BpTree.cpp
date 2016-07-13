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

// Function to search key k in subtree rooted with this node
BTreeNode* BTreeNode::find(int k){
    // Find the first key greater than or equal to k
    int i = 0;
    while (i < n && k > keys[i])
        i++;
 
    // If the found key is equal to k, return this node
    if (keys[i] == k)
        return this;
 
    // If key is not found here and this is a leaf node
    if (leaf == true)
        return NULL;
 
    // Go to the appropriate child
    return C[i]->find(k);
}

void BTreeNode::insertFull(int k){
    // Allocate memory for new root
    BTreeNode *nr = new BTreeNode(t, false);
 
    // Make old root as child of new root
    nr->C[0] = root;
 
    // Split the old root and move 1 key to the new root
    nr->splitChild(0, root);
 
    // New root has two children now.  Decide which of the
    // two children is going to have new key
    int i = 0;
    if (nr->keys[0] < k)
    i++;
    nr->C[i]->insertNonFull(k);
 
    // Change root
    root = nr;
}

void BTreeNode::insertnonFull(int k){
   
}
    
void BTreeNode::splitChild(int i, BTreeNode *y){
    
}

// Constructor for BpTree 
BpTree::BpTree(int _n){  
    // (Initializes tree as empty)
    root = NULL;  
    // Copy down the given maximum number of search key value
    n = _n; 
}

// Function to search a key in this tree
BTreeNode* BpTree::find(int k){  
    return (root == NULL)? NULL : root->find(k); 
}

void BpTree::insert(int k){
    // If tree is empty
    if (root == NULL)
    {
        // Allocate memory for root
        root = new BTreeNode(t, true);
        root->keys[0] = k;  // Insert key
        root->ck = 1;  // Update number of keys in root
    }
    else // If tree is not empty
    {
        // If root is full, then tree grows in height
        if (root->ck == n)
        {
            root->insertFull(k);
        }
        else  // If root is not full, call insertNonFull for root
            root->insertNonFull(k);
    }
}