#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
/* Time Complexity is O(N) & Space Complexity is O(N) --> for the use of the two
 * extra stck */
struct Node {
  int data;
  struct Node *left, *right;
};

void SpiralLevelOrder(Node *root) {
  if (root == NULL)
    return;
  stack<Node *> s1;
  stack<Node *> s2;
  s1.push(root);
  while (!s1.empty() || !s2.empty()) {
    while (!s1.empty()) {
      Node *temp = s1.top();
      cout << temp->data << " ";
      s1.pop();
      if (temp->right)
        s2.push(temp->right);
      if (temp->left)
        s2.push(temp->left);
    }
    while (!s2.empty()) {
      Node *temp = s2.top();
      cout << temp->data << " ";
      s2.pop();
      if (temp->left)
        s1.push(temp->left);
      if (temp->right)
        s1.push(temp->right);
    }
  }
}

struct Node *newNode(int data) {
  struct Node *node = new struct Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return (node);
}
/*============Main()====================*/

int main() {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(7);
  root->left->right = newNode(6);
  root->right->left = newNode(5);
  root->right->right = newNode(4);
  cout << "Spiral Order traversal of binary tree is \n";
  SpiralLevelOrder(root);

  return 0;
}
