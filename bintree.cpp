/***************************************************************************
Name: Natalia Ksenz
Coding 07
Purpose: The assignment to create a Binary tree object with Data and Node
structures.

File: bintree.cpp
***************************************************************************/

#include "bintree.h"

BinTree::BinTree() {
    root = NULL;
    count = 0;
}

BinTree::~BinTree() {
    clear();
}

bool BinTree::isEmpty() {
    bool empty = true;
    if (root != NULL) {
        empty = false;
    };
    return empty;
}

int BinTree::getCount() {
    return count;
}

bool BinTree::getRootData(Data *data) {
  if (root != NULL) {
      data->id = root->data.id;
      data->information = root->data.information;
  }
  else {
      data->id = -1;
      data->information = "";
  }
  return data;
}

void BinTree::displayTree() {
    cout << "DISPLAY TREE\n" << string(46,'=') << endl;
    if (root == NULL) {
      cout << "Tree is empty" << endl;
    }
    else {
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height " << getHeight() << endl;
    cout << "Node count " << getCount() << endl;

    cout << "\nPre-Order Traversal" << endl;
    displayPreOrder();
    cout << "\nIn-Order Traversal" << endl;
    displayInOrder();
    cout << "\nPost-Order Traversal" << endl;
    displayPostOrder();
    cout << "\n" << string(46,'=') << endl << endl;
}

void BinTree::clear() {
    clear(root);
}

//public methods
bool BinTree::addNode(int id, const string *info) {
    return 0;
}

bool BinTree::removeNode(int id) {
    return 0;
}

bool BinTree::getNode(Data*, int) {
    return 0;
}

bool BinTree::contains(int id) {
    return 0;
}

int BinTree::getHeight() {
    return getHeight(root);
}

void BinTree::displayPreOrder() {
    displayPreOrder(root);
}

void BinTree::displayPostOrder() {
    displayPostOrder(root);
}

void BinTree::displayInOrder() {
    displayInOrder(root);
}

void BinTree::clear(DataNode*) {

}

//overloaded methods
bool BinTree::addNode(DataNode *newNode, DataNode **root) {
    return 0;
}

DataNode *BinTree::removeNode(int id, DataNode *temproot) {
    return 0;
}

bool BinTree::getNode(Data*, int, DataNode*) {
    return 0;
}

bool BinTree::contains(int id, DataNode *temproot) {
    return 0;
}

int BinTree::getHeight(DataNode* temproot) {
    int lh = 0, rh = 0;
    if (temproot != NULL) {
        if (temproot->left != NULL) {
            getHeight(temproot->left);
            lh++;
        }
        if (temproot->right != NULL) {
            getHeight(temproot->right);
            rh++;
        }
    }
    return temproot == NULL ? 0 : max(lh, rh) + 1;
}

void BinTree::displayPreOrder(DataNode *temproot) {
    return;
}

void BinTree::displayPostOrder(DataNode *temproot) {
    return;
}

void BinTree::displayInOrder(DataNode *temproot) {
    return;
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
