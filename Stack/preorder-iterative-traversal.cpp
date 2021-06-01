#include <bits/stdc++.h>
using namespace std;

struct node {
  int data;
  node *left;
  node *right;
};

node *newNode(int data) {
  node *temp = new node();
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

/*===========Your Code Here=============*/
void IterativePreOrder(node *root) {
  if (root == NULL)
    return;
  stack<node *> st;
  st.push(root);
  while (st.empty() == false) {
    node *temp = st.top();
    cout << temp->data << "->";
    st.pop();
    if (temp->right)
      st.push(temp->right);
    if (temp->left)
      st.push(temp->left);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  node *root = newNode(10);
  root->left = newNode(8);
  root->right = newNode(2);
  root->left->left = newNode(3);
  root->left->right = newNode(5);
  root->right->left = newNode(2);
  IterativePreOrder(root);
  cout << endl;
  return 0;
}
