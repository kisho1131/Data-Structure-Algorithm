#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  Node *left, *right;
};

bool CheckMirrorTree(Node *root1, Node *root2) {
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;

  return (root1->data == root2->data) &&
         CheckMirrorTree(root1->left, root2->right) &&
         CheckMirrorTree(root2->right, root1->left);
}
Node *newNode(int data) {
  Node *node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

int main() {
  Node *a = newNode(1);
  Node *b = newNode(1);
  a->left = newNode(2);
  a->right = newNode(3);
  a->left->left = newNode(4);
  a->left->right = newNode(5);

  b->left = newNode(3);
  b->right = newNode(2);
  b->right->left = newNode(5);
  b->right->right = newNode(4);

  CheckMirrorTree(a, b) ? cout << "Yes" : cout << "No";

  return 0;
}
