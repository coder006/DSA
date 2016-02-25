#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node  *node = new Node();
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

void printLevel(Node *root, int lev) {
    if(root == NULL)
        return;
    else if(lev == 1)
        cout << root->data << " ";
    else if(lev > 1) {
        printLevel(root->left, lev-1);
        printLevel(root->right, lev-1);
    }
}

int main() {
    Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);

    int k = 2;
    // Pass 'k+1' to printLevel because distance is k
    printLevel(root, k+1);
    cout << endl;
}