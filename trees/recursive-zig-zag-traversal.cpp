#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

Node* createNode(int data) {
    Node *newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

int maximum(int a, int b) {
    if(a > b)
        return a;
    else
        return b;
}

int height(Node *root) {
    if(root == NULL)
        return -1;
    else if(root->left == NULL && root->right == NULL)
        return 0;

    return maximum(height(root->left), height(root->right)) + 1; 
} 

void printLevel(Node *root, bool alt, int lev) {
    if(root == NULL)
        return;
    else if(lev == 1)
        cout << root->data << " ";
    else if(lev > 1) {
        if(alt) {
            printLevel(root->left, alt, lev-1);
            printLevel(root->right, alt, lev-1);
        }
        else {
            printLevel(root->right, alt, lev-1);
            printLevel(root->left, alt, lev-1);
        }
    }
}

void printZigZag(Node *root) {
    int h = height(root);
    cout << "height == " << h << endl;
    bool alt = false;

    for(int i = 1; i <= h+1; i++) {
        printLevel(root, alt, i);
        alt = !alt;
        cout << endl;
    }
}

int main() {
    Node *root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);

    printZigZag(root);
}