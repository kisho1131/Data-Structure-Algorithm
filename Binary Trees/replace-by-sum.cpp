#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  Node *left;
  Node *right;
  int data;
};
struct Node *getNode(int data) {
  struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
  new_node->data = data;
  new_node->left = new_node->right = NULL;
  return new_node;
}
void inOrderStore(Node *root, vector<int> &arr) {
  if (root == NULL)
    return;
  inOrderStore(root->left, arr);
  arr.push_back(root->data);
  inOrderStore(root->right, arr);
}
void replaceNodeWithSum(Node *root, vector<int> arr, int *i) {
  if (root == NULL)
    return;
  replaceNodeWithSum(root->left, arr, i);
  root->data = arr[*i - 1] + arr[*i + 1];
  ++*i;
  replaceNodeWithSum(root->right, arr, i);
}

void replaceNodeWithSumUtil(Node *root) {
  if (root == NULL)
    return;
  vector<int> arr;
  arr.push_back(0);
  inOrderStore(root, arr);
  arr.push_back(0);
  int i = 1;
  replaceNodeWithSum(root, arr, &i);
}
void preOrder(Node *root) {
  if (root == NULL)
    return;
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = getNode(1); /*         1        */
  root->left = getNode(2);        /*       /   \      */
  root->right = getNode(3);       /*     2      3     */
  root->left->left = getNode(4);  /*    /  \  /   \   */
  root->left->right = getNode(5); /*   4   5  6   7   */
  root->right->left = getNode(6);
  root->right->right = getNode(7);
  preOrder(root);
  replaceNodeWithSumUtil(root);
  cout << endl;
  preOrder(root);
  cout << endl;
  return 0;
}
