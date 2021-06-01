#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  struct Node *left, *right;
};

Node *newNode(int k) {
  Node *temp = new Node;
  temp->data = k;
  temp->left = temp->right = NULL;
  return temp;
}

bool findPath(Node *root, vector<int> &path, int key) {
  if (root == NULL)
    return false;
  path.push_back(root->data);
  if (root->data == key)
    return true;
  if ((root->left && findPath(root->left, path, key)) ||
      (root->right && findPath(root->right, path, key)))
    return true;
  path.pop_back();
  return false;
}

int findLCA(Node *root, int n1, int n2) {
  if (root == NULL)
    return -1;
  vector<int> path1, path2;
  if (!findPath(root, path1, n1) || !findPath(root, path2, n2))
    return -1;
  int i;
  for (i = 0; i < path1.size() && i < path2.size(); i++) {
    if (path1[i] != path2[i])
      break;
  }
  return path1[i - 1];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl;
  cout << "LCA(4, 6) = " << findLCA(root, 4, 6) << endl;
  cout << "LCA(3, 4) = " << findLCA(root, 3, 4) << endl;
  cout << "LCA(2, 4) = " << findLCA(root, 2, 4) << endl;
  cout << endl;
  return 0;
}
