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

void BinTree::clear() {
    clear(root);
}

//public methods
bool BinTree::addNode(int id, const string *info) {
    return 0;
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

void BinTree::clear(DataNode*) {

}

//overloaded methods
bool BinTree::addNode(DataNode *newNode, DataNode **root) {
    return 0;
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
                (getNode(tempdata, id, temproot->left));
            }
            if (id > temproot->data.id) {
                (getNode(tempdata, id, temproot->right));
            }
        }
    }
    return found;
}

bool BinTree::contains(int id, DataNode *temproot) {
    bool found = false;
    if (temproot != NULL) {
        if (temproot->data.id == id) {
            found = true;
        }
        else {
            if (id < temproot->data.id) {
                (contains(id, temproot->left));
            }
            if (id > temproot->data.id) {
                (contains(id, temproot->right));
            }
        }
    }
    return found;
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
