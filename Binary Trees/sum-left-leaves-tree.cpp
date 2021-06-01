#include <bits/stdc++.h>
using namespace std;
static int sum = 0;
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
void LeftTreeSum(Node *root) {
  if (root == NULL)
    return;
  if (root->left && root->left->left == NULL && root->left->right == NULL)
    sum += root->left->data;
  LeftTreeSum(root->left);
  LeftTreeSum(root->right);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newNode(20);
  root->left = newNode(9);
  root->right = newNode(49);
  root->right->left = newNode(23);
  root->right->right = newNode(52);
  root->right->right->left = newNode(50);
  root->left->left = newNode(5);
  root->left->right = newNode(12);
  root->left->right->right = newNode(12);
  LeftTreeSum(root);
  cout << sum;
  cout << endl;
  return 0;
}
