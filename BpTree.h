#ifndef BPTREE_H
#define BPTREE_H
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
 
    // A function to traverse all nodes in a subtree rooted with this node
    void traverse();
    
    int prints();
 
    // A function to search a key in subtree rooted with this node.    
    BTreeNode *search(int k);   // returns NULL if k is not present.
 
// Make BTree friend of this so that we can access private members of this
// class in BTree functions
friend class BTree;
};
 
// A BTree
class BTree
{
    BTreeNode *root; // Pointer to root node
    int n;  // Number of search keys 
public:
    // Constructor (Initializes tree as empty)
    BTree(int _n)
    {  root = NULL;  n = _n; }
 
    // function to traverse the tree
    void traverse()
    {  if (root != NULL) root->traverse(); }
 
    // function to search a key in this tree
    BTreeNode* search(int k)
    {  return (root == NULL)? NULL : root->search(k); }
};

#endif //BPTREE_H
