#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  Node *left, *right;
};

Node *getNode(int data) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = data;
  newNode->left = newNode->right = NULL;
  return newNode;
}
void MaxPathLenSumUtil(Node *root, int sum, int len, int &maxSum, int &maxLen) {
  if (root == NULL)
    return;
  if (root->left == NULL && root->right == NULL) {
    if (maxLen < len) {
      maxLen = len;
      maxSum = sum;
    } else if (maxLen == len && maxSum < sum)
      maxSum = sum;
    return;
  }
  MaxPathLenSumUtil(root->left, sum + root->data, len + 1, maxSum, maxLen);
  MaxPathLenSumUtil(root->right, sum + root->data, len + 1, maxSum, maxLen);
}
int PrintPathMaxSum(Node *root) {
  if (root == NULL)
    return 0;
  int maxSum = INT_MIN;
  int maxLen = 0;
  MaxPathLenSumUtil(root, 0, 0, maxSum, maxLen);
  return maxSum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = getNode(4);         /*        4        */
  root->left = getNode(2);         /*       / \       */
  root->right = getNode(5);        /*      2   5      */
  root->left->left = getNode(7);   /*     / \ / \     */
  root->left->right = getNode(1);  /*    7  1 2  3    */
  root->right->left = getNode(2);  /*      /          */
  root->right->right = getNode(3); /*     6           */
  root->left->right->left = getNode(6);
  cout << PrintPathMaxSum(root);
  cout << endl;
  return 0;
}
