#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node *getNewNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = node->right = NULL;
  return node;
}
/*===========Your Code Here=============*/
int TreeSize(Node *root) {
  if (root == NULL)
    return 0;
  int left = TreeSize(root->left);
  int right = TreeSize(root->right);
  int total = left + right + 1;
  return total;
}
// Height--> no of Edges from root to the Leave Node --> return -1;
// Height--> No of node from root to the leave Node --> return 0;
int TreeHeight(Node *root) {
  if (root == NULL)
    return -0;
  int leftHeight = TreeHeight(root->left);
  int rightHeight = TreeHeight(root->right);
  int totalHeight = max(leftHeight, rightHeight) + 1;
  return totalHeight;
}

int MaxElement(Node *root) {
  if (root == NULL)
    return INT_MIN;
  int maxLeft = MaxElement(root->left);
  int maxRight = MaxElement(root->right);
  int maxEle = max(root->data, max(maxLeft, maxRight));
  return maxEle;
}

int TreeElementSum(Node *root) {
  if (root == NULL)
    return 0;
  int leftSum = TreeElementSum(root->left);
  int rightSum = TreeElementSum(root->right);
  int totalSum = leftSum + rightSum + root->data;
  return totalSum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = getNewNode(30);
  root->left = getNewNode(40);
  root->right = getNewNode(12);
  root->left->left = getNewNode(34);
  root->left->right = getNewNode(56);
  root->right->left = getNewNode(87);
  cout << TreeSize(root);
  cout << endl;
  cout << TreeElementSum(root);
  cout << endl;
  cout << MaxElement(root);
  cout << endl;
  cout << TreeHeight(root);
  return 0;
}
