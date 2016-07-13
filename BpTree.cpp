#include<iostream>
#include <cstddef>
#include "BpTree.h"
#include <string> 
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

void BTreeNode::insertNonFull(int k){
   // Initialize index as index of rightmost element
    int i = n-1;

    // If this is a leaf node
    if (leaf == true)
    {
        // The following loop does two things
        // a) Finds the location of new key to be inserted
        // b) Moves all greater keys to one place ahead
        while (i >= 0 && keys[i] > k)
        {
            keys[i+1] = keys[i];
            i--;
        }

        // Insert the new key at found location
        keys[i+1] = k;
        n = n+1;
    }
    else // If this node is not leaf
    {
        // Find the child which is going to have the new key
        while (i >= 0 && keys[i] > k)
            i--;

        // See if the found child is full
        if (C[i+1]->ck == n)
        {
            // If the child is full, then split it
            splitChild(i+1, C[i+1]);

            // After split, the middle key of C[i] goes up and
            // C[i] is splitted into two. See which of the two
            // is going to have the new key
            if (keys[i+1] < k)
                i++;
        }
        C[i+1]->insertNonFull(k);
    }
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

void BTreeNode::splitChild(int i, BTreeNode *y){
    // Create a new node which is going to store (n) keys
    // of y
    BTreeNode *z = new BTreeNode(y->n, y->leaf);
    z->ck = n - 1;

    // Copy the last (n-1) keys of y to z
    for (int j = 0; j < n-1; j++)
        z->keys[j] = y->keys[j+n];

    // Copy the last t children of y to z
    if (y->leaf == false)
    {
        for (int j = 0; j < n; j++)
            z->C[j] = y->C[j+n];
    }

    // Reduce the number of keys in y
    y->ck = n - 1;

    // Since this node is going to have a new child,
    // create space of new child
    for (int j = ck; j >= i+1; j--)
        C[j+1] = C[j];

    // Link the new child to this node
    C[i+1] = z;

    // A key of y will move to this node. Find location of
    // new key and move all greater keys one space ahead
    for (int j = n-1; j >= i; j--)
        keys[j+1] = keys[j];

    // Copy the middle key of y to this node
    keys[i] = y->keys[n-1];

    // Increment count of keys in this node
    ck = ck + 1;
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


// The main function that inserts a new key
void BpTree::insert(int k){
    // If tree is empty
    if (root == NULL)
    {
        // Allocate memory for root
        root = new BTreeNode(n, true);
        root->keys[0] = k; // Insert key
        root->n = 1; // Update number of keys in root
    }
    else // If tree is not empty
    {
           // If root is full, then tree grows in height
        if (root->ck == n)
        {
            // Allocate memory for new root
            BTreeNode *nr = new BTreeNode(n, false);

            // Make old root as child of new root
            nr->C[0] = root;

            // Split the old root and move 1 key to the new root
            nr->splitChild(0, root);

            // New root has two children now. Decide which of the
            // two children is going to have new key
            int i = 0;
            if (nr->keys[0] < k)
                i++;
            nr->C[i]->insertNonFull(k);

            // Change root
            root = nr;
        }
        else // If root is not full, call insertNonFull for root
            root->insertNonFull(k);
    }
}



