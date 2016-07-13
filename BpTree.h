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
    int ck;     // Current number of search keys
    bool leaf; // Is true when node is leaf. Otherwise false
    
    void inserFull(int k);
    
    void insertNonFull(int k);
    
    void splitChild(int i, BTreeNode *y);
    
public:
    BTreeNode(int _n, bool _leaf);   // Constructor
    
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    
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
    
    void insert(int k);
};

#endif //BPTREE_H
