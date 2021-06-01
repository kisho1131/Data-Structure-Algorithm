#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
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

Node *ConvertToBSTUtil(int pre[], int st, int ed, int *preIdx, int size) {
  if (st > ed)
    return NULL;
  Node *root = newNode(pre[*preIdx]);
  *preIdx = *preIdx + 1;
  int i;
  for (i = st; i <= ed; i++) {
    if (root->data < pre[i])
      break;
  }
  if (st == ed)
    return root;
  root->left = ConvertToBSTUtil(pre, *preIdx, i - 1, preIdx, size);
  root->right = ConvertToBSTUtil(pre, i, ed, preIdx, size);
  return root;
}

Node *ConvertToBST(int pre[], int size) {
  int st = 0;
  int ed = size - 1;
  int preIdx = 0;
  return ConvertToBSTUtil(pre, st, ed, &preIdx, size);
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
  int pre[] = {10, 5, 1, 7, 40, 50};
  int size = sizeof(pre) / sizeof(pre[0]);
  Node *root = ConvertToBST(pre, size);
  Inorder(root);
  cout << endl;
  return 0;
}
