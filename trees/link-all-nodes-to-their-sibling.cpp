#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *left, *right, *next;
};

Node* newNode(int data) {
    Node *node = new Node();
    node->data = data;
    node->left = node->right = node->next = NULL;

    return node;
}

void linkNodes(Node *root) {
    if(root == NULL)
        return;
    // Check for left child
    if(root->left != NULL) 
        if(root->right != NULL)
            root->left->next = root->right;
        else {
            if(root->next != NULL)
                if(root->next->left != NULL)
                    root->left->next = root->next->left;
                else if(root->next->right != NULL)
                    root->left->next = root->next->right;
            else
                root->left->next = NULL;
        }

    // Check for right child
    if(root->right != NULL) 
        if(root->next != NULL)
            if(root->next->left != NULL)
                root->right->next = root->next->left;
            else if(root->next->right != NULL)
                root->right->next = root->next->right;
        else
            root->right->next = NULL;

    // Recursively link children of left and right child
    linkNodes(root->left);
    linkNodes(root->right);
}

int maximum(int a, int b) {
    if(a > b)
        return a;
    return b;
}

int height(Node *root) {
    if(root == NULL)
        return 0;
    return maximum(height(root->left), height(root->right)) + 1;
}

void printLevel(Node *root, int lev) {
    if(root == NULL)
        return;
    else if(lev == 1)
        if(root->next != NULL)
            cout << root->data << "->";
        else
            cout << root->data << "->NULL ";
    else if(lev > 1){
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

    root->next = NULL;

    linkNodes(root);
    levelOrderTraversal(root);
}