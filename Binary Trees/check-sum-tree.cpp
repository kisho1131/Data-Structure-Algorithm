#include <bits/stdc++.h>
using namespace std;

/* Time complexity is O(N^2) */

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

int Sum(Node *root) {
  if (root == NULL)
    return 0;
  return Sum(root->left) + Sum(root->right) + root->data;
}
/*===========Your Code Here=============*/
int CheckSumTree(Node *root) {
  if (root == NULL || (root->left == NULL && root->right == NULL))
    return 1;
  int ls = Sum(root->left);
  int rs = Sum(root->right);
  if ((ls + rs == root->data) && CheckSumTree(root->left) &&
      CheckSumTree(root->right))
    return 1;
  return 0;
}
/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(26);
  root->left = newNode(10);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(6);
  root->right->right = newNode(3);
  if (CheckSumTree(root))
    cout << "The given tree is a SumTree ";
  else
    cout << "The given tree is not a SumTree ";
  return 0;
}
