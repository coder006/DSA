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

bool checkKLengthPath(Node *root, int sum, int k) {
    if(root == NULL)
        if(sum == k)
            return true;
        else
            return false;

    if(root->left == NULL && root->right == NULL) {
        if((sum + root->data) == k)
            return true;
        else
            return false;
    }

    if(root->left != NULL && checkKLengthPath(root->left, (sum + root->data), k))
        return true;
    if(root->right != NULL && checkKLengthPath(root->right, (sum + root->data), k))
        return true;

    return false;
}

int main() {
    Node *root = newNode(5);
    root->left = newNode(3);
    root->right = newNode(7);
    root->left->left = newNode(2);
    root->left->right = newNode(4);
    root->right->left = newNode(6);
    root->right->right = newNode(8);

    bool pathExists = checkKLengthPath(root, 0, 20);
    if(pathExists)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
