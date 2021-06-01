#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

/*===========Your Code Here=============*/

Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

void ReverseTreePathUtil(Node *root, vector<Node *> path, int pathCount,
                         int key) {
  path[pathCount] = root;
  pathCount++;
  if (root->data == key) {
    int i = 0;
    int j = pathCount - 1;
    while (i < j) {
      int temp = path[i]->data;
      path[i]->data = path[j]->data;
      path[j]->data = temp;
      i++;
      j--;
    }
  }
  if (!root->left && !root->right)
    return;
  ReverseTreePathUtil(root->left, path, pathCount, key);
  ReverseTreePathUtil(root->right, path, pathCount, key);
}
void ReverseTreePath(Node *root, int key) {
  if (root == NULL)
    return;
  vector<Node *> path;
  int pathCount = 0;
  ReverseTreePathUtil(root, path, pathCount, key);
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
  Node *root = newNode(7);
  root->left = newNode(6);
  root->right = newNode(5);
  root->left->left = newNode(4);
  root->left->right = newNode(3);
  root->right->left = newNode(2);
  root->right->right = newNode(1);
  Inorder(root);
  cout << endl;
  ReverseTreePath(root, 4);
  Inorder(root);
  cout << endl;
  return 0;
}
