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

void BSTtoGreaterSumTreeUtil(Node *root, int *sum) {
  if (root == NULL)
    return;
  BSTtoGreaterSumTreeUtil(root->right, sum);
  *sum = *sum + root->data;
  root->data = *sum - root->data;
  BSTtoGreaterSumTreeUtil(root->left, sum);
}
void BSTtoGreaterSumTree(Node *root) {
  int sum = 0;
  BSTtoGreaterSumTreeUtil(root, &sum);
}

void Inorder(Node *root) {
  if (root == NULL)
    return;
  Inorder(root->left);
  cout << root->data << " ";
  Inorder(root->right);
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
  Inorder(root);
  cout << endl;
  BSTtoGreaterSumTree(root);
  Inorder(root);
  cout << endl;
  return 0;
}
