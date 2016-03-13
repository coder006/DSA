#include <iostream>

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

Node* createMirror(Node *root) {
    if(root == NULL)
        return NULL;

    Node *newroot = newNode(root->data);
    newroot->left = createMirror(root->right);
    newroot->right = createMirror(root->left);

    return newroot;
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

void levelOrderTraversal(Node *root) {
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

    Node *new_root = createMirror(root);
    levelOrderTraversal(root);
    cout << endl << "----------"  << endl;
    levelOrderTraversal(new_root);
}
