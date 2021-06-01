#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  Node *left;
  Node *right;
  Node *next;
};

Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = node->right = node->next = NULL;
  return node;
}
void PopulateNext(Node *root) {
  static Node *next = NULL;
  if (root) {
    PopulateNext(root->right);
    root->next = next;
    next = root;
    PopulateNext(root->left);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(10);
  root->left = newNode(8);
  root->right = newNode(12);
  root->left->left = newNode(3);

  // Populates nextRight pointer in all nodes
  PopulateNext(root);

  // Let us see the populated values
  Node *ptr = root->left->left;
  while (ptr) {
    // -1 is printed if there is no successor
    cout << "Next of " << ptr->data << " is "
         << (ptr->next ? ptr->next->data : -1) << endl;
    ptr = ptr->next;
  }

  return 0;
}
