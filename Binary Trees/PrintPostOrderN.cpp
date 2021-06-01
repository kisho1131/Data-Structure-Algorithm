// C++ program to print Postorder traversal from
// given Inorder and Preorder traversals.

// Time Complexity - O(N)

#include <bits/stdc++.h>
using namespace std;

int preIndex = 0;
void printPost(int in[], int pre[], int inStrt, int inEnd, map<int, int> hm) {
  if (inStrt > inEnd)
    return;
  int inIndex = hm[pre[preIndex]];
  preIndex++;
  printPost(in, pre, inStrt, inIndex - 1, hm);
  printPost(in, pre, inIndex + 1, inEnd, hm);
  cout << in[inIndex] << " ";
}

void printPostMain(int in[], int pre[], int n) {
  map<int, int> hm;
  for (int i = 0; i < n; i++)
    hm[in[i]] = i; // Storing the Value & Index of the Element
  printPost(in, pre, 0, n - 1, hm);
}

// Driver code
int main() {
  int in[] = {4, 2, 5, 1, 3, 6};
  int pre[] = {1, 2, 4, 5, 3, 6};
  int n = sizeof(pre) / sizeof(pre[0]);
  printPostMain(in, pre, n);
  return 0;
}
