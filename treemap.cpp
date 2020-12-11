#include "treemap.h"

template <typename ValType>
TreeMap<ValType>::TreeMap() {
    root = NULL;
}

template <typename ValType>
TreeMap<ValType>::~TreeMap() {
    FreeTree(root);
}

template <typename ValType>
ValType TreeMap<ValType>::getValue(string key)   // getValue is wrapper
{  
    node *found = treeSearch(root, key);
    if (found == NULL) {
        cout << "getValue of non-existent key!";
        exit(0);
    } else {
        return found->val;
    }     
}

template <typename ValType>
void TreeMap<ValType>::add(string key, ValType val)  // add is wrapper
{  
    treeEnter(root, key, val);
}

template <typename ValType>
void TreeMap<ValType>::printTree() 
{
    inorderTraverse(root);
}

template <typename ValType>
typename TreeMap<ValType>::node *TreeMap<ValType>::treeSearch(node *t, string key) 
{
    if (t == NULL) return NULL;  // doesn't exist

    if (key == t->key)
        return t;  // found match
    else if (key < t->key)
        return treeSearch(t->left, key);  // search left
    else
        return treeSearch(t->right, key); // search right
}

template <typename ValType>
void TreeMap<ValType>::treeEnter(node *&t, string key, ValType val) 
{
    if (t == NULL) {
        t = new node;
        t->key = key;
        t->val = val;
        t->left = t->right = NULL;
    } else if (key == t->key) {
        t->val = val;
    } else if (key < t->key) {
        treeEnter(t->left, key, val);
    } else {
        treeEnter(t->right, key, val);
    }   
}

template <typename ValType>
void TreeMap<ValType>::inorderTraverse(node *t) 
{
    if (t != NULL) {
        printTree(t->left);
        cout << t->val << endl;
        printTree(t->right);
    }
}

template <typename ValType>
void TreeMap<ValType>::FreeTree(node *&t) 
{
    if (t != NULL) {
        FreeTree(t->left);
        FreeTree(t->right);
        delete t;
    }
}