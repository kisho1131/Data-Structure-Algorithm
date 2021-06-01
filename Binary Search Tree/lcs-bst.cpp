#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

int LcaBst(Node *node, int d1, int d2) {
  if (d1 < node->data and d2 < node->data)
    return LcaBst(node->left, d1, d2);
  else if (d1 > node->data and d2 > node->data)
    return LcaBst(node->right, d1, d2);
  return node->data;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(20);
  root->left = newNode(8);
  root->right = newNode(22);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);
  cout << LcaBst(root, 10, 14);
  return 0;
}
