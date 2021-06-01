#include <bits/stdc++.h>
using namespace std;

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

/*===========Your Code Here=============*/
void Inorder(Node *root) {
  if (root == NULL)
    return;
  Inorder(root->left);
  cout << root->data << " ";
  Inorder(root->right);
}

int ConvertToSumTree(Node *root) {
  if (root == NULL)
    return 0;
  int node_data = root->data;
  root->data = ConvertToSumTree(root->left) + ConvertToSumTree(root->right);
  return root->data + node_data;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  cout << endl;
  Node *root = NULL;
  root = newNode(10);
  root->left = newNode(-2);
  root->right = newNode(6);
  root->left->left = newNode(8);
  root->left->right = newNode(-4);
  root->right->left = newNode(7);
  root->right->right = newNode(5);
  int sum = ConvertToSumTree(root);
  Inorder(root);
  return 0;
}
