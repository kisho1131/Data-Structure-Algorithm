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

void PrintPath(int path[], int len) {
  for (int i = 0; i < len; i++) {
    cout << path[i] << " ";
  }
  cout << endl;
}

void RootToTreePath(Node *root, int path[], int pathLen) {
  if (root == NULL)
    return;
  path[pathLen++] = root->data;
  if (root->left == NULL && root->right == NULL) {
    PrintPath(path, pathLen);
  }
  RootToTreePath(root->left, path, pathLen);
  RootToTreePath(root->right, path, pathLen);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  int path[1000];
  RootToTreePath(root, path, 0);
  cout << endl;
  return 0;
}
