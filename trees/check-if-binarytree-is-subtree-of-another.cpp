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
    if(root1 == NULL && root2 != NULL)
        return false;
    return (root1->data == root2->data &&
        checkIdentical(root1->left, root2->left) &&
        checkIdentical(root1->right, root2->right));
}

bool checkSubtree(Node *root1, Node *root2) {
    if(root1 == NULL)
        return false;
    if(root2 == NULL)
        return true;
    if(checkIdentical(root1, root2))
        return true;
    return (checkIdentical(root1->left, root2) ||
            checkIdentical(root1->right, root2));
}

int main() {
    Node *root1 = newNode(5);
    root1->left = newNode(3);
    root1->right = newNode(7);
    root1->left->left = newNode(2);
    root1->left->right = newNode(4);
    root1->right->left = newNode(6);
    root1->right->right = newNode(8);

    Node *root2 = newNode(3);
    root2->left = newNode(2);
    root2->right = newNode(5);

    bool isSubtree = checkSubtree(root1, root2);
    if(isSubtree)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
