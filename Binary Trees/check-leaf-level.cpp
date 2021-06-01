#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  struct Node *left, *right;
};
struct Node *newNode(int data) {
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = data;
  node->left = node->right = NULL;
  return node;
}
bool CheckLeafLevelUtil(Node *root, int level, int *leafLevel) {
  if (root == NULL)
    return true;
  if (root->left == NULL && root->right == NULL) {
    if (*leafLevel == 0) {
      *leafLevel = level;
      return true;
    } //  We are Encountring the First Leaf
    return (*leafLevel == level);
  }
  return CheckLeafLevelUtil(root->left, level + 1, leafLevel) and
         CheckLeafLevelUtil(root->right, level + 1, leafLevel);
}

bool CheckLeafLevel(Node *root) {
  int level = 0;
  int leafLevel = 0;
  return CheckLeafLevelUtil(root, level, &leafLevel);
}

/* Time Complexity: The function does a simple traversal of the tree, so the
 * complexity is O(n) */

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newNode(12);
  root->left = newNode(5);
  root->left->left = newNode(3);
  root->left->right = newNode(9);
  root->left->left->left = newNode(1);
  root->left->right->left = newNode(1);
  if (CheckLeafLevel(root))
    cout << "Leaves are at same level\n";
  else
    cout << "Leaves are not at same level\n";
  cout << endl;
  return 0;
}
