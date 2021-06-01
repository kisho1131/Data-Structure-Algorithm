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

void DiagonalSum(Node *root) {
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);
  Node *curr = NULL;
  int sum = 0;
  int count = 1;
  while (!q.empty()) {
    if (curr == NULL) {
      curr = q.front();
      q.pop();
      count--;
    }
    sum += curr->data;
    if (curr->left)
      q.push(curr->left);
    curr = curr->right;
    if (curr == NULL && count == 0) {
      cout << sum << " ";
      sum = 0;
      count = q.size();
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(9);
  root->left->right = newNode(6);
  root->right->left = newNode(4);
  root->right->right = newNode(5);
  root->right->left->right = newNode(7);
  root->right->left->left = newNode(12);
  root->left->right->left = newNode(11);
  root->left->left->right = newNode(10);
  DiagonalSum(root);
  cout << endl;
  return 0;
}
