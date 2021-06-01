#include <bits/stdc++.h>
using namespace std;

/*===========Your Code Here=============*/

struct Node {
  int key;
  struct Node *left, *right;
};
struct Node *newNode(int key) {
  Node *temp = new Node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return (temp);
}

void PrintMiddleLevel(Node *slow, Node *fast) {
  if (fast == NULL || slow == NULL)
    return;
  if (fast->left == NULL && fast->right == NULL) {
    cout << slow->key << " ";
    return;
  }
  if (fast->left->left) {
    PrintMiddleLevel(slow->left, fast->left->left);
    PrintMiddleLevel(slow->right, fast->left->left);
  } else {
    PrintMiddleLevel(slow->left, fast->left);
    PrintMiddleLevel(slow->right, fast->left);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  Node *n1 = newNode(1);
  Node *n2 = newNode(2);
  Node *n3 = newNode(3);
  Node *n4 = newNode(4);
  Node *n5 = newNode(5);
  Node *n6 = newNode(6);
  Node *n7 = newNode(7);
  n2->left = n4;
  n2->right = n5;
  n3->left = n6;
  n3->right = n7;
  n1->left = n2;
  n1->right = n3;
  PrintMiddleLevel(n1, n1);
  cout << endl;
  return 0;
}
