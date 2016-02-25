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

bool checkIdentical(Node *root1, Node *root2) {
    if(root1 == NULL && root2 == NULL)
        return true;
    else if(root1->data == root2->data) {
        return (checkIdentical(root1->left, root2->left) && 
            checkIdentical(root1->right, root2->right));
    }
    else
        return false;
}

int main() {
    Node *root1 = newNode(1);
    Node *root2 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5); 
 
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    bool isIdentical = checkIdentical(root1, root2);
    if(isIdentical)
        cout << "Identical Trees" << endl;
    else
        cout << "Unidentical Trees" << endl;
}