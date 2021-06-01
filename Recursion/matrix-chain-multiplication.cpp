#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int p[], int i, int j) {
  if (i == j)
    return 0;
  int min = INT_MAX;
  int count = 0;
  for (int k = i; k < j; k++) {
    count = MatrixChainMultiplication(p, i, k) +
            MatrixChainMultiplication(p, k + 1, j) + p[i - 1] * p[k] * p[j];
    if (count < min)
      min = count;
  }
  return min;
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i = 1;
  int j = n - 1;
  cout << MatrixChainMultiplication(arr, i, j);
  return 0;
}
