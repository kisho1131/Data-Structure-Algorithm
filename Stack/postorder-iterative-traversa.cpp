#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};
Node *newNode(int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}

/*===========Your Code Here=============*/
void PostOrder(Node *root) {
  stack<Node *> s1;
  stack<Node *> s2;
  s1.push(root);
  while (!s1.empty()) {
    Node *temp = s1.top();
    s1.pop();
    s2.push(temp);
    if (temp->left)
      s1.push(temp->left);
    if (temp->right)
      s1.push(temp->right);
  }

  while (!s2.empty()) {
    cout << s2.top()->data << " ";
    s2.pop();
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(10);
  root->left = newNode(8);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  PostOrder(root);
  cout << endl;
  return 0;
}
