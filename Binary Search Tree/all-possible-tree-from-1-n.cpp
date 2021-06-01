#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
struct node {
  int key;
  struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item) {
  struct node *temp = new node;
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// A utility function to do preorder traversal of BST
void preorder(struct node *root) {
  if (root != NULL) {
    cout << root->key << " ";
    preorder(root->left);
    preorder(root->right);
  }
}
vector<node *> ConvertToBST(int start, int end) {
  vector<node *> RootList;
  if (start > end) {
    RootList.push_back(NULL);
    return RootList;
  }
  for (int i = start; i <= end; i++) {
    vector<node *> leftRoots = ConvertToBST(start, i - 1);
    vector<node *> rightRoots = ConvertToBST(i + 1, end);
    for (int j = 0; j < leftRoots.size(); j++) {
      node *left = leftRoots[j];
      for (int k = 0; k < rightRoots.size(); k++) {
        node *right = rightRoots[k];
        node *root = newNode(i);
        root->left = left;
        root->right = right;
        RootList.push_back(root);
      }
    }
  }
  return RootList;
}

/*============Main()====================*/
int main() {
  // Construct all possible BSTs
  vector<struct node *> totalTreesFrom1toN = ConvertToBST(1, 3);

  /*  Printing preorder traversal of all constructed BSTs   */
  cout << "Preorder traversals of all constructed BSTs are \n";
  for (int i = 0; i < totalTreesFrom1toN.size(); i++) {
    preorder(totalTreesFrom1toN[i]);
    cout << endl;
  }
  return 0;
}
