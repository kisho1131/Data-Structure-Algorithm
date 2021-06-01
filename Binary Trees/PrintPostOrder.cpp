#include <bits/stdc++.h>
using namespace std;

// Time Complexity - > O(N^2)
/*===========Your Code Here=============*/

int preIdx = 0;
int Search(int in[], int data, int n) {
  for (int i = 0; i < n; i++) {
    if (in[i] == data)
      return i;
  }
  return -1;
}
void PrintPostOrder(int in[], int pre[], int n) {
  int idx = Search(in, pre[0], n);
  if (idx != 0)
    PrintPostOrder(in, pre + 1, idx);
  if (idx != n - 1)
    PrintPostOrder(in + idx + 1, pre + idx + 1, n - idx - 1);
  cout << pre[0] << " ";
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int in[] = {4, 2, 5, 1, 3, 6};
  int pre[] = {1, 2, 4, 5, 3, 6};
  int len = sizeof(in) / sizeof(in[0]);
  PrintPostOrder(in, pre, len);
  cout << endl;
  return 0;
}
