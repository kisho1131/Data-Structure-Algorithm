#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  struct Node *left, *right;
};

// A utility function to create a new Binary Tree Node
struct Node *newNode(int item) {
  struct Node *temp = new Node;
  temp->data = item;
  temp->left = temp->right = NULL;
  return temp;
}

void MorrisTraversal(Node *root) {
  Node *curr = root;
  int count = 0;
  while (curr != NULL) {
    if (curr->left == NULL) {
      cout << curr->data << " ";
      count++;
      curr = curr->right;
    } else {
      Node *pre = curr->left;
      while (pre->right != NULL && pre->right != curr)
        pre = pre->right;
      if (pre->right == NULL) {
        pre->right = curr;
        curr = curr->left;
      } else {
        pre->right = NULL;
        cout << curr->data << " ";
        count++;
        curr = curr->right;
      }
    }
  }
  cout << endl;
  cout << count;
  cout << endl;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newNode(11);
  root->left = newNode(2);
  root->right = newNode(29);
  root->left->left = newNode(1);
  root->left->right = newNode(7);
  root->right->left = newNode(15);
  root->right->right = newNode(40);
  root->right->right->left = newNode(35);
  MorrisTraversal(root);
  cout << endl;
  return 0;
}
