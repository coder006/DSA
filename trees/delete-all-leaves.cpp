#include <iostream>
#include <stdlib.h>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

Node* deleteLeves(Node *root) {
    if(root == NULL)
        return NULL;
    else if(root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }
    else {
        root->left = deleteLeves(root->left);
        root->right = deleteLeves(root->right);
    }
    return root;
}

int maximum(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int height(Node *root) {
    if(root == NULL)
        return 0;
    else
        return maximum(height(root->left), height(root->right)) + 1;
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

void printLevelOrderTraversal(Node *root) {
    int h = height(root);
    for(int i = 1; i <= h; i++) {
        printLevel(root, i);
        cout << endl;
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

    cout << "---- Old Tree ----" << endl;
    printLevelOrderTraversal(root);
    
    root = deleteLeves(root);
    cout << endl;
    
    cout << "---- New Tree ----" << endl;
    printLevelOrderTraversal(root);
}