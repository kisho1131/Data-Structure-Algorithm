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
void DiagonalTraversal(Node *root) {
  if (root == NULL)
    return;
  queue<Node *> qu;
  qu.push(root);
  while (!qu.empty()) {
    Node *temp = qu.front();
    qu.pop();
    while (temp) {
      if (temp->left)
        qu.push(temp->left);
      cout << temp->data << " ";
      temp = temp->right;
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(8);
  root->left = newNode(3);
  root->right = newNode(10);
  root->left->left = newNode(1);
  root->left->right = newNode(6);
  root->right->right = newNode(14);
  root->right->right->left = newNode(13);
  root->left->right->left = newNode(4);
  root->left->right->right = newNode(7);
  DiagonalTraversal(root);
  cout << endl;
  return 0;
}
