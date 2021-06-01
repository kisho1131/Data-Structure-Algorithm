#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

/*===========Your Code Here=============*/

Node *newNode(int data) {
  Node *node = new Node();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return NULL;
}

int Search(int in[], int startIndex, int endIndex, int key) {
  for (int i = startIndex; i <= endIndex; i++) {
    if (in[i] == key)
      return i;
  }
  return -1;
}

Node *BuildTree(int in[], int pre[], int startIndex, int endIndex) {
  if (startIndex > endIndex)
    return NULL;
  static int preIndex = 0;
  Node *rootNode = newNode(pre[preIndex++]);

  /* If the node has no childern  i.e it is leave node */
  if (startIndex == endIndex)
    return rootNode;

  int inIndex = Search(in, startIndex, endIndex, rootNode->data);
  rootNode->left = BuildTree(in, pre, startIndex, inIndex - 1);
  rootNode->right = BuildTree(in, pre, inIndex + 1, endIndex);
  return rootNode;
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
  int in[] = {4, 2, 5, 1, 6, 3, 7};
  int pre[] = {1, 2, 4, 5, 3, 6, 7};
  int startIndex = 0;
  int len = sizeof(in) / sizeof(in[0]);
  int endIndex = len - 1;
  Node *rootNode = BuildTree(in, pre, startIndex, endIndex);
  Inorder(rootNode);
  cout << endl;
  return 0;
}
