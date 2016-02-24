#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *left, *right;
};

struct Node * addNode( int data ) {
    Node *newnode = new Node();
    newnode->data = data;
    newnode->left = newnode->right = NULL;

    return newnode;
}

bool isSibling(Node *root, Node *p, Node *q) {
    if(root == NULL)
        return 0;

    return((root->left == p && root->right == q) || (root->right == p && root->left == q) || 
        isSibling(root->left, p, q) || isSibling(root->right, p, q));
}

int findLevel(Node *root, Node *n, int lev) {
    if(root == NULL)
        return 0;
    else if(root == n)
        return lev;
    
    int l = findLevel(root->left, n, lev+1);
    if(l != 0)
        return l;
    else
        return findLevel(root->right, n, lev+1);
}

bool checkCousins(Node *root, Node *p, Node *q) {
    if(findLevel(root, p, 1) == findLevel(root, q, 1)) {
        if(!isSibling(root, p, q))
            return true;
        else
            return false;
    }
    else
        return false;
}

int main() {
    Node *root = addNode(5);
    root->left = addNode(4);
    root->right = addNode(6);
    Node *p = root->left->left = addNode(2);
    root->left->right = addNode(3);
    root->right->right = addNode(8);
    Node *q = root->right->left = addNode(7);

    bool isCousin = checkCousins(root, p, q);
    cout << isCousin << endl;
}