#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct Node {
  int data;
  struct Node *left, *right;
};

struct Node *newnode(int data) {
  struct Node *node = new Node;
  node->data = data;
  node->left = node->right = NULL;
  return (node);
}

bool PairSumUtil(Node *curr, unordered_set<int> &mp, int rootData) {
  if (curr == NULL)
    return false;
  int diff = curr->data - rootData;
  if (mp.find(diff) != mp.end())
    return true;
  mp.insert(curr->data);
  bool res = (PairSumUtil(curr->left, mp, rootData) ||
              PairSumUtil(curr->right, mp, rootData));
  mp.erase(curr->data);
  return res;
}

bool PairSum(Node *root) {
  unordered_set<int> mp; // Hash Map
  int rootData = root->data;
  return PairSumUtil(root->left, mp, rootData) ||
         PairSumUtil(root->right, mp, rootData);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  struct Node *root = newnode(8);
  root->left = newnode(5);
  root->right = newnode(4);
  root->left->left = newnode(9);
  root->left->right = newnode(7);
  root->left->right->left = newnode(1);
  root->left->right->right = newnode(12);
  root->left->right->right->right = newnode(2);
  root->right->right = newnode(11);
  root->right->right->left = newnode(3);
  cout << PairSum(root);
  cout << endl;
  return 0;
}
