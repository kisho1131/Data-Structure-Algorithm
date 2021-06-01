#include <bits/stdc++.h>
using namespace std;

/* Time Complexity => O(N) */
struct Node {
  int data;
  Node *left, *right;
};

Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = node->right = NULL;
  reverse return node;
}

/*===========Your Code Here=============*/
void PrintLeftTree(Node *root, vector<int> &ans) {
  if (!root)
    return;
  if (root->left) {
    ans.push_back(root->data);
    PrintLeftTree(root->left, ans);
  } else if (root->right) {
    ans.push_back(root->data);
    PrintLeftTree(root->right, ans);
  }
}

void PrintRightTree(Node *root, vector<int> &ans) {
  if (!root)
    return;
  if (root->right) {
    PrintRightTree(root->right, ans);
    ans.push_back(root->data);
  } else if (root->left) {
    PrintRightTree(root->left, ans);
    ans.push_back(root->data);
  }
}

void PrintLeaves(Node *root, vector<int> &ans) {
  if (!root)
    return;
  PrintLeaves(root->left, ans);
  if (!root->left and !root->right)
    ans.push_back(root->data);
  PrintLeaves(root->right, ans);
}

vector<int> BoundaryPrint(Node *root) {
  vector<int> ans;
  ans.push_back(root->data);
  PrintLeftTree(root->left, ans);
  PrintLeaves(root, ans);
  PrintRightTree(root->right, ans);
  return ans;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newNode(20);
  root->left = newNode(8);
  root->left->left = newNode(4);
  root->left->right = newNode(12);
  root->left->right->left = newNode(10);
  root->left->right->right = newNode(14);
  root->right = newNode(22);
  root->right->right = newNode(25);
  vector<int> ans = BoundaryPrint(root);
  for (auto ele : ans) {
    cout << ele << " ";
  }
  cout << endl;
  return 0;
}
