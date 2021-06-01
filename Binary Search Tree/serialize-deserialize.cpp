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

int currIdx = 0;
Node *Deserialize(int pre[], int min, int max, int n) {
  if (currIdx == n)
    return NULL;
  Node *root = NULL;
  if (pre[currIdx] > min && pre[currIdx] < max) {
    root = newNode(pre[currIdx]);
    currIdx++;
    root->left = Deserialize(pre, min, root->data, n);
    root->right = Deserialize(pre, root->data, max, n);
  }
  return root;
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
  int pre[] = {5, 2, 1, 3, 4, 7, 6, 8};
  int n = sizeof(pre) / sizeof(pre[0]);
  int min = INT_MIN;
  int max = INT_MAX;
  Node *root = Deserialize(pre, min, max, n);
  Inorder(root);
  cout << endl;
  return 0;
}
