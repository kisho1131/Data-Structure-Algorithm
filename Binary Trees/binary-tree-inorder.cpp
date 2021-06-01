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

int max(int inOrder[], int start, int end) {
  int maxEle = inOrder[start];
  int maxIdx = start;
  for (int itr = start; itr <= end; itr++) {
    if (inOrder[itr] > maxEle) {
      maxEle = inOrder[itr];
      maxIdx = itr;
    }
  }
  return maxIdx;
}

Node *BuildTree(int inOrder[], int start, int end) {
  if (start > end)
    return NULL;
  int index = max(inOrder, start, end);
  Node *root = newNode(inOrder[index]);
  if (start == end)
    return root;
  root->left = BuildTree(inOrder, start, index - 1);
  root->right = BuildTree(inOrder, index + 1, end);
  return root;
}

void Traversal(Node *root) {
  if (root == NULL)
    return;
  Traversal(root->left);
  cout << root->data << " ";
  Traversal(root->right);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int inorder[] = {1, 5, 10, 40, 30, 15, 28, 20};
  int n = sizeof(inorder) / sizeof(int);
  Node *root = BuildTree(inorder, 0, n - 1);
  Traversal(root);
  cout << endl;
  return 0;
}
