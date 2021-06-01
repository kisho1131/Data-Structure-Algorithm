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
Node *FlipBinaryTree(Node *root) {
  if (root == NULL)
    return root;
  if (root->left == NULL && root->right == NULL)
    return root;
  Node *node = FlipBinaryTree(root->left);
  root->left->left = root->right;
  root->left->right = root;
  root->left = NULL;
  root->right = NULL;
  return node;
}
void printLevelOrder(Node *root) {
  if (root == NULL)
    return;
  printLevelOrder(root->left);
  cout << root->data << " ";
  printLevelOrder(root->right);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->right->left = newNode(4);
  root->right->right = newNode(5);
  cout << "Level order traversal of given tree\n";
  printLevelOrder(root);
  root = FlipBinaryTree(root);
  cout << "\nLevel order traversal of the flipped"
          " tree\n";
  printLevelOrder(root);
  return 0;
  cout << endl;
  return 0;
}
