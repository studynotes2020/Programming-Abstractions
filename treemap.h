#ifndef TREEMAP_H
#define TREEMAP_H

#include <string>
#include <iostream>

using namespace std;

template <typename ValType>
class TreeMap 
{
  public:
      TreeMap();
      ~TreeMap();

      void add(string key, ValType val);
      ValType getValue(string key);
      void printTree();
    
  private:
    struct node {
      string key;
      ValType val;
      node *left, *right;
    };
    node *root;
    node *treeSearch(node * t, string key);
    void treeEnter(node *&t, string key, ValType val);
    void inorderTraverse(node * t);
    void FreeTree(node *&t);
};

#include "TreeMap.cpp"

#endif