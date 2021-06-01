#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

/*===========Your Code Here=============*/
Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

Node *Array2BinaryTree(int arr[], Node *root, int i, int n) {
  if (i < n) {
    Node *temp = newNode(arr[i]);
    root = temp;
    root->left = Array2BinaryTree(arr, root->left, 2 * i + 1, n);
    root->right = Array2BinaryTree(arr, root->right, 2 * i + 2, n);
  }
  return root;
}

void inOrder(Node *root) {
  if (root == NULL)
    return;
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 5, 6, 6, 6, 6};
  int n = sizeof(arr) / sizeof(arr[0]);
  Node *root = Array2BinaryTree(arr, root, 0, n);
  inOrder(root);
  cout << endl;
  return 0;
}
