#include "Header.h"

// Реализация методов класса RBTree

void RBTree::rotateLeft(Node*& node) {
    Node* rightChild = node->right;
    node->right = rightChild->left;

    if (rightChild->left != nullptr) {
        rightChild->left->parent = node;
    }

    rightChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = rightChild;
    }
    else if (node == node->parent->left) {
        node->parent->left = rightChild;
    }
    else {
        node->parent->right = rightChild;
    }

    rightChild->left = node;
    node->parent = rightChild;
}

void RBTree::rotateRight(Node*& node) {
    Node* leftChild = node->left;
    node->left = leftChild->right;

    if (leftChild->right != nullptr) {
        leftChild->right->parent = node;
    }

    leftChild->parent = node->parent;

    if (node->parent == nullptr) {
        root = leftChild;
    }
    else if (node == node->parent->right) {
        node->parent->right = leftChild;
    }
    else {
        node->parent->left = leftChild;
    }

    leftChild->right = node;
    node->parent = leftChild;
}

void RBTree::balanceInsert(Node*& node) {
    Node* parent = nullptr;
    Node* grandparent = nullptr;

    while (node != root && node->color == RED && node->parent->color == RED) {
        parent = node->parent;
        grandparent = parent->parent;

        if (parent == grandparent->left) {
            Node* uncle = grandparent->right;

            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            }
            else {
                if (node == parent->right) {
                    rotateLeft(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateRight(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
        else {
            Node* uncle = grandparent->left;

            if (uncle != nullptr && uncle->color == RED) {
                grandparent->color = RED;
                parent->color = BLACK;
                uncle->color = BLACK;
                node = grandparent;
            }
            else {
                if (node == parent->left) {
                    rotateRight(parent);
                    node = parent;
                    parent = node->parent;
                }

                rotateLeft(grandparent);
                swap(parent->color, grandparent->color);
                node = parent;
            }
        }
    }

    root->color = BLACK;
}

void RBTree::insert(char data) {
    Node* newNode = new Node(data);

    if (root == nullptr) {
        root = newNode;
        root->color = BLACK;
    }
    else {
        Node* temp = root;

        while (true) {
            if (data < temp->data) {
                if (temp->left == nullptr) {
                    temp->left = newNode;
                    newNode->parent = temp;
                    break;
                }
                else {
                    temp = temp->left;
                }
            }
            else if (data > temp->data) {
                if (temp->right == nullptr) {
                    temp->right = newNode;
                    newNode->parent = temp;
                    break;
                }
                else {
                    temp = temp->right;
                }
            }
            else {
                delete newNode;
                return;
            }
        }

        balanceInsert(newNode);
    }
}

void RBTree::inorderTraversal(Node* node, vector<char>& result) const {
    if (node == nullptr) return;
    inorderTraversal(node->left, result);
    result.push_back(node->data);
    inorderTraversal(node->right, result);
}

vector<char> RBTree::inorder() const {
    vector<char> result;
    inorderTraversal(root, result);
    return result;
}

int RBTree::findPathLength(Node* node, char value, int length) const {
    if (node == nullptr) return -1;
    if (node->data == value) return length;

    int leftPath = findPathLength(node->left, value, length + 1);
    if (leftPath != -1) return leftPath;

    return findPathLength(node->right, value, length + 1);
}

int RBTree::getPathLength(char value) const {
    return findPathLength(root, value, 0);
}

void RBTree::calculateSumAndCount(Node* node, int& sum, int& count) const {
    if (node == nullptr) return;
    calculateSumAndCount(node->left, sum, count);
    sum += static_cast<int>(node->data);
    count++;
    calculateSumAndCount(node->right, sum, count);
}

double RBTree::getAverage() const {
    int sum = 0, count = 0;
    calculateSumAndCount(root, sum, count);
    return count == 0 ? 0.0 : static_cast<double>(sum) / count;
}
