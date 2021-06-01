#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  Node *left;
  Node *right;
};
Node *newNode(int data) {
  Node *temp = new Node();
  temp->data = data;
  temp->left = temp->right = NULL;
  return temp;
}
/*===========Your Code Here=============*/
void IterativeInorder(Node *root) {
  Node *curr = root;
  stack<Node *> st;
  while (curr != NULL || !st.empty()) {
    while (curr != NULL) {
      /* code */
      st.push(curr);
      curr = curr->left;
    }
    curr = st.top();
    st.pop();
    cout << curr->data << "->";
    curr = curr->right;
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *root = newNode(10);
  root->left = newNode(8);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  IterativeInorder(root);
  cout << endl;
  return 0;
}
