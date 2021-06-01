#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left, *right;
};

Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = node->right = NULL;
  return node;
}

/*===========Your Code Here=============*/
void ReverseLevelOrder(Node *root) {
  if (root == NULL)
    return;
  queue<Node *> qu;
  stack<Node *> st;
  qu.push(root);
  while (!qu.empty()) {
    Node *temp = qu.front();
    qu.pop();
    st.push(temp);
    if (temp->right)
      qu.push(temp->right);
    if (temp->left)
      qu.push(temp->left);
  }
  while (!st.empty()) {
    Node *temp = st.top();
    st.pop();
    cout << temp->data << " ";
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  ReverseLevelOrder(root);
  cout << endl;
  return 0;
}
