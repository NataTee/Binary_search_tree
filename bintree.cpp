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
    return 0;
}

void BinTree::displayTree() {
    return;
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
    return;
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
    return;
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
