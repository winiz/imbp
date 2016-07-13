#ifndef BPTREE_H
#define BPTREE_H
#include <iostream>
#include <cstddef>

// A BTree node
class BTreeNode
{
    int n;      // Maximum number of search keys 
    int *keys;  // An array of keys
    BTreeNode **C; // An array of child pointers
    int ck;     // Current number of keys
    bool leaf; // Is true when node is leaf. Otherwise false
public:
    BTreeNode(int _n, bool _leaf);   // Constructor
 
    // A function to search a key in subtree rooted with this node.    
    // returns NULL if k is not present.
    BTreeNode *find(int k); 
 
// Make BTree friend of this so that we can access private members of this
// class in BTree functions
friend class BTree;
};


class BpTree
{
    BTreeNode *root; // Pointer to root node
    int n;  // Number of search keys 
public:
    // Constructor (Initializes tree as empty)
    BpTree(int _n);
    
    // function to search a key in this tree
    BTreeNode* find(int k);
};

#endif //BPTREE_H
