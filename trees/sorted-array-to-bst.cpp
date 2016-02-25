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

Node* createBST(int arr[], int l, int r) {
    if(l > r)
        return NULL;
    int mid = (l + r) / 2;
    Node *root = newNode(arr[mid]);
    root->left = createBST(arr, l, mid-1);
    root->right = createBST(arr, mid+1, r);

    return root;
}

void printInOrder(Node *root) {
    if(root != NULL) {
        printInOrder(root->left);
        cout << root->data << " ";
        printInOrder(root->right);
    }
}

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *root = createBST(arr, 0, n-1);
    printInOrder(root);
    cout << endl;
}