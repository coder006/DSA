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

int distRoot(Node *root, Node *node, int dist) {
  if(node->data == root->data)
    return dist;
  else if(node->data < root->data)
    return distRoot(root->left, node, dist - 1);
  else if(node->data > root->data)
    return distRoot(root->right, node, dist + 1);
}

void findDist(Node *root, Node *a, Node *b) {
  int d1 = distRoot(root, a, 0);
  int d2 = distRoot(root, b, 0);
  cout << d2 - d1 << endl;
}

int main() {
  Node *root = newNode(5);
  root->left = newNode(3);
  root->right = newNode(7);
  root->left->left = newNode(2);
  root->left->right = newNode(4);
  root->right->left = newNode(6);
  root->right->right = newNode(8);

  findDist(root, root->left->right, root->right->right);
}
