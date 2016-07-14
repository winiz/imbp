#ifndef BPTREE_H
#define BPTREE_H
#include <iostream>
#include <cstddef>
#include <string> 

// A BTree node
class BTreeNode{
private:
    int n;      // Maximum number of search keys 
    int *keys;  // An array of keys 
    BTreeNode **C; // An array of child pointers (Maximum n+1 of them)
    int ck;     // Current number of search keys
    bool leaf; // Is true when node is leaf. Otherwise false
    // A utility function to insert a new key in the subtree rooted with
    // this node. The assumption is, the node must be non-full when this
    // function is called
    void insertNonFull(int k);
    // A utility function to split the child y of this node. i is index of y in
    // child array C[].  The Child y must be full when this function is called
    void splitChild(int i, BTreeNode *y);
    // Make BTree friend of this so that we can access private members of this
    // class in BTree functions
    
    // A function to search a key in subtree rooted with this node.    
    // returns NULL if k is not present.
    BTreeNode *findNode(int k); 
    
public:
    BTreeNode(int _n, bool _leaf);   // Constructor
    
    // Alow BpTree to have access to the private fields in here 
    friend class BpTree;
};


class BpTree{
private:
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
