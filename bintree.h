/***************************************************************************
Name: Natalia Ksenz
Coding 07
Purpose: The assignment to create a Binary tree object with Data and Node
structures.

File: bintree.h
***************************************************************************/

#ifndef BINTREE_BINTREE_H
#define BINTREE_BINTREE_H

#include <iostream>
#include <string>
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class BinTree {
public:

    BinTree();
    ~BinTree();

    //tree management without overloads
    bool isEmpty();
    int getCount();
    bool getRootData(Data*);

    //tree management with private overloads
    void clear();
    bool addNode(int, const string*);
    bool removeNode(int);
    bool getNode(Data*, int);
    bool contains(int);
    int getHeight();

    //display functions with private overloads
    void displayPreOrder();
    void displayPostOrder();
    void displayInOrder();

    //doesn't need overload
    void displayTree();

private:

    DataNode *root;
    int count;

    //overloaded tree management
    void clear(DataNode*);
    bool addNode(DataNode*, DataNode**);
    bool removeNode(int, DataNode*);
    bool getNode(Data*, int, DataNode*);
    bool contains(int, DataNode*);
    int getHeight(DataNode*);

    //overloaded display functions
    void displayPreOrder(DataNode*);
    void displayPostOrder(DataNode*);
    void displayInOrder(DataNode*);
};

#endif /* BINTREE_BINTREE_H */
