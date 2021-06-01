#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void MirrorTreeIterative(Node *root) {
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);
  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    swap(curr->left, cur->right);
    if (curr->left)
      q.push(curr->left);
    if (curr->right)
      q.push(curr->right);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  MirrorTreeIterative(root);
  cout << endl;
  return 0;
}
