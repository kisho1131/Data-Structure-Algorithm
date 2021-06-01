#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *node(int data) {
  Node *n = new Node();
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/*===========Your Code Here=============*/
void increment(Node *root, int diff) {
  if (root->left != NULL) {
    root->left->data += diff;
    increment(root->left, diff);
  } else if (root->right != NULL) {
    root->right->data += diff;
    increment(root->right, diff);
  }
}

void Inorder(Node *root) {
  if (root == NULL)
    return;
  Inorder(root->left);
  cout << root->data << " ";
  Inorder(root->right);
}

void ConvertTree(Node *root) {
  int left_data = 0, right_data = 0, diff;
  if (root == NULL)
    return;
  if (root->left == NULL && root->right == NULL)
    return;
  ConvertTree(root->left);
  ConvertTree(root->right);
  if (root->left != NULL)
    left_data = root->left->data;

  if (root->right != NULL)
    right_data = root->right->data;

  diff = left_data + right_data - root->data;
  if (diff > 0) {
    root->data += diff;
  }
  if (diff < 0)
    increment(root, -diff);
  /* using (-)ve sign to convert the diff to positive value */
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = node(50);
  root->left = node(7);
  root->right = node(2);
  root->left->left = node(3);
  root->left->right = node(5);
  root->right->left = node(1);
  root->right->right = node(30);
  Inorder(root);
  cout << endl;
  ConvertTree(root);
  Inorder(root);
  cout << endl;
  return 0;
}

/* Time complexity of the solution is O(N^2) for the screwed Trees */
