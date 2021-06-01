#include <bits/stdc++.h>
using namespace std;

/* A binary tree Node has data, pointer to left child and a pointer to right
 * child */
struct Node {
  int data;
  struct Node *left;
  struct Node *right;
  Node(int data) {
    this->data = data;
    left = right = NULL;
  }
};

void RecInorder(Node *root) {
  if (root == NULL) {
    return;
  }
  RecInorder(root->left);
  cout << root->data << " ";
  RecInorder(root->right);
}

void LevelOrder(Node *root) {
  queue<Node *> qu;
  Node *curr = root;
  qu.push(curr);
  while (!qu.empty()) {
    curr = qu.front();
    cout << curr->data << " ";
    qu.push(curr->left);
    qu.push(curr->right);
    qu.pop();
  }
}

/* Iterative function for inorder tree traversal */
void inOrder(struct Node *root) {
  stack<Node *> s;
  Node *curr = root;
  while (curr != NULL || s.empty() == false) {
    while (curr != NULL) {
      s.push(curr);
      curr = curr->left;
    }
    curr = s.top();
    s.pop();
    cout << curr->data << " ";
    curr = curr->right;
  }
}

/* Driver program to test above functions*/
int main() {
  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  RecInorder(root);
  cout << endl;
  inOrder(root);
  cout << endl;
  LevelOrder(root);
  return 0;
}
