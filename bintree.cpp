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
  bool found = false;
  if (root != NULL) {
      data->id = root->data.id;
      data->information = root->data.information;
      found = true;
  }
  else {
      data->id = -1;
      data->information = "";
  }
  return found;
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

//public methods
void BinTree::clear() {
    clear(root);
    count = 0;
}

bool BinTree::addNode(int id, const string *info) {
    bool added = false;
    if(id > 0 && *info != "") {
        DataNode *newNode = new DataNode;
        newNode->data.id = id;
        newNode->data.information = *info;
        newNode->left = NULL;
        newNode->right = NULL;
        if (addNode(newNode, &root)) {
            added = true;
            count++;
        }
    }
    return added;
}

bool BinTree::removeNode(int id) {
    int tempcount = count;
    root = removeNode(id, root);
    return count < tempcount ? true : false;
}

bool BinTree::getNode(Data *tempdata, int id) {
    bool found = false;
    if (id > 0) {
        if (getNode(tempdata, id, root)) {
            found = true;
        }
    }
    return found;
}

bool BinTree::contains(int id) {
    bool found = false;
    if (id > 0) {
        if (contains(id, root)) {
            found = true;
        }
    }
    return found;
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

//private overloads
void BinTree::clear(DataNode *temproot) {
    if (temproot != NULL) {
        clear(temproot->left);
        clear(temproot->right);
        temproot->left = NULL;
        temproot->right = NULL;
        delete temproot;
    }
    root = NULL;
    return;
}

bool BinTree::addNode(DataNode *newNode, DataNode **temproot) {
    bool added = false;
    if (!(*temproot)) {
        *temproot = newNode;
        (*temproot)->data.id = newNode->data.id;
        (*temproot)->data.information = newNode->data.information;
        (*temproot)->left = NULL;
        (*temproot)->right = NULL;
        added = true;
    }
    else {
        if(newNode->data.id < (*temproot)->data.id) {
            addNode(newNode, &(*temproot)->left);
        }
        if(newNode->data.id > (*temproot)->data.id) {
            addNode(newNode, &(*temproot)->right);
        }
        added = true;
    }
    return added;
}

DataNode *BinTree::removeNode(int id, DataNode *temproot) {
    if (temproot != NULL) {
        if (id < temproot->data.id) {
            temproot->left = removeNode(id, temproot->left);
        }
        else if (id > temproot->data.id) {
            temproot->right = removeNode(id, temproot->right);
        }
        else {
            DataNode *temp;
            if (temproot->left == NULL) {
                temp = temproot->right;
                delete temproot;
                temproot = temp;
                count--;
            }
            else if (temproot->right == NULL) {
                temp = temproot->left;
                delete temproot;
                temproot = temp;
                count--;
            }
            else {
                temp = minValueNode(temproot->right);
                temproot->data.id = temp->data.id;
                temproot->data.information = temp->data.information;
                temproot->right = removeNode(temp->data.id, temproot->right);
            }
        }
    }
    return temproot;
}

bool BinTree::getNode(Data *tempdata, int id, DataNode *temproot) {
    bool found = false;
    if (temproot != NULL) {
        if (temproot->data.id == id) {
            tempdata->id == temproot->data.id;
            tempdata->information == temproot->data.information;
            found = true;
        }
        else {
            if (id < temproot->data.id) {
                found = getNode(tempdata, id, temproot->left);
            }
            if (id > temproot->data.id) {
                found = getNode(tempdata, id, temproot->right);
            }
        }
    }
    return found;
}

bool BinTree::contains(int id, DataNode *temproot) {
    bool found;
    if (temproot != NULL) {
        if (temproot->data.id == id) {
            found = true;
        }
        else {
            if (id < temproot->data.id) {
                found = contains(id, temproot->left);
            }
            if (id > temproot->data.id) {
                found = contains(id, temproot->right);
            }
        }
    }
    else {
        found = false;
    }
    return found;
}

int BinTree::getHeight(DataNode* temproot) {
    int lh = 0, rh = 0, height = 0;
    if (temproot != NULL) {
        if (temproot->left != NULL) {
            lh = getHeight(temproot->left);
        }
        if (temproot->right != NULL) {
            rh = getHeight(temproot->right);
        }
        height = lh > rh ? lh + 1 : rh + 1;
    }
    return height;
}

void BinTree::displayPreOrder(DataNode *temproot) {
    if (temproot) {
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->left) {
            displayPreOrder(temproot->left);
        }
        if (temproot->right) {
            displayPreOrder(temproot->right);
        }
    }
    return;
}

void BinTree::displayInOrder(DataNode *temproot) {
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }
    return;
}

void BinTree::displayPostOrder(DataNode *temproot) {
    if (temproot) {
        if (temproot->left) {
            displayPostOrder(temproot->left);
        }
        if (temproot->right) {
            displayPostOrder(temproot->right);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
    }
    return;
}

DataNode* BinTree::minValueNode(DataNode* node) {
    DataNode* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}
