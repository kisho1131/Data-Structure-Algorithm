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
void Tree2DLL(Node *root, Node **head) {
  if (root == NULL)
    return;
  static Node *prev = NULL;

  Tree2DLL(root->left, head);
  if (prev == NULL) { /*This is the First Node in the Doubly Linked List*/
    *head = root;
  } else {
    prev->right = root;
    root->left = prev;
  }
  prev = root;
  Tree2DLL(root->right, head);
}

void PrintList(Node *head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->right;
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(10);
  root->left = newNode(12);
  root->right = newNode(15);
  root->left->left = newNode(25);
  root->left->right = newNode(30);
  root->right->left = newNode(36);
  Node *head = NULL;
  Tree2DLL(root, &head);
  PrintList(head);
  cout << endl;
  return 0;
}
