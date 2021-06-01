#include <bits/stdc++.h>
using namespace std;

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

void Inorder(Node *root) {
  if (root == NULL)
    return;
  cout << root->data << " ";
  Inorder(root->left);
  Inorder(root->right);
}
/*===========Your Code Here=============*/
int findIndex(string str, int si, int ei) {
  if (si > ei)
    return -1;
  stack<char> s;
  for (int i = si; i <= ei; i++) {
    if (str[i] == '(')
      s.push(str[i]);
    else if (str[i] == ')') {
      if (s.top() == '(') {
        s.pop();
        if (s.empty())
          return i;
      }
    }
  }
  return -1;
}
Node *String2Tree(string str, int start, int end) {
  if (start > end)
    return NULL;
  Node *root = newNode(str[start] - '0');
  int index = -1;
  if (start + 1 <= end && str[start + 1] == '(')
    index = findIndex(str, start + 1, end);

  if (index != -1) {
    root->left = String2Tree(str, start + 2, index - 1);
    root->right = String2Tree(str, index + 2, end - 1);
  }
  return root;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str = "4(2(3)(1))(6(5))";
  Node *root = String2Tree(str, 0, str.length() - 1);
  Inorder(root);
  cout << endl;
  return 0;
}
