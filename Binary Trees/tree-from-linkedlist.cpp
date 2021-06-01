#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct LinkedList {
  int data;
  LinkedList *next;
};

struct TreeNode {
  int data;
  TreeNode *left;
  TreeNode *right;
};

TreeNode *newTreeNode(int data) {
  TreeNode *node = new TreeNode();
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void ListPush(LinkedList **head, int data) {
  LinkedList *node = new LinkedList;
  node->data = data;
  node->next = (*head);
  (*head) = node;
}

void convertList2Binary(LinkedList *head, TreeNode *&root) {
  if (head == NULL) {
    root = NULL;
    return;
  }
  queue<TreeNode *> q;
  root = newTreeNode(head->data);
  q.push(root);
  head = head->next;
  while (head) {
    TreeNode *parent = q.front();
    q.pop();
    TreeNode *leftNode = NULL, *rightNode = NULL;
    if (head) {
      leftNode = newTreeNode(head->data);
      q.push(leftNode);
      head = head->next;
    }

    if (head) {
      rightNode = newTreeNode(head->data);
      head = head->next;
      q.push(rightNode);
    }
    parent->left = leftNode;
    parent->right = rightNode;
  }
}

void inOrder(TreeNode *root) {
  if (root) {
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  LinkedList *head = NULL;
  ListPush(&head, 36);
  ListPush(&head, 30);
  ListPush(&head, 25);
  ListPush(&head, 15);
  ListPush(&head, 12);
  ListPush(&head, 10);
  // ListPush(&head, 17);
  TreeNode *root;
  convertList2Binary(head, root);
  inOrder(root);
  cout << endl;
  return 0;
}
