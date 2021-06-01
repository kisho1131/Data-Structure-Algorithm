#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *getNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void PrintPath(vector<int> path, int n) {
  for (int i = 0; i < n; i++) {
    cout << path[i] << " ";
  }
}
void Root2GivenNode(Node *root, int key, vector<int> path, int pathLen) {
  if (root == NULL)
    return;
  path[pathLen++] = root->data;
  if (root->data == key) {
    PrintPath(path, pathLen);
  }
  Root2GivenNode(root->left, key, path, pathLen);
  Root2GivenNode(root->right, key, path, pathLen);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = getNode(1);
  root->left = getNode(2);
  root->right = getNode(3);
  root->left->left = getNode(4);
  root->left->right = getNode(5);
  root->right->left = getNode(6);
  root->right->right = getNode(7);
  vector<int> path(1000);
  Root2GivenNode(root, 5, path, 0);
  cout << endl;
  return 0;
}
