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
void MirrorTree(Node *root) {
  if (root == NULL)
    return;
  Node *temp;
  MirrorTree(root->left);
  MirrorTree(root->right);
  temp = root->left;
  root->left = root->right;
  root->right = temp;
}

void Inorder(Node *root) {
  if (root == NULL)
    return;
  Inorder(root->left);
  cout << root->data << " ";
  Inorder(root->right);
}
/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  Inorder(root);
  cout << endl;
  MirrorTree(root);
  Inorder(root);
  cout << endl;
  return 0;
}
