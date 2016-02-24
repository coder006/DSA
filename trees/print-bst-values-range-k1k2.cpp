#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node *newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

void printBSTInRange(Node *root, int k1, int k2) {
    if(root == NULL)
        return;
    if(root->data > k1)
        printBSTInRange(root->left, k1, k2);
    if(root->data >=k1 && root->data <= k2)
        cout << root->data << " ";
    if(root->data < k2)
        printBSTInRange(root->right, k1, k2);
}

int main() {
    Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);

    printBSTInRange(root, 3, 7);
}