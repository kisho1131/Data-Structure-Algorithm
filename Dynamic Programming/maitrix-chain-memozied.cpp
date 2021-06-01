#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int arr[], int i, int j) {
  int count = 0;
  if (i == j)
    return 0;
  int dp[i + 1][j + 1];
  memset(dp, -1, sizeof(dp));
  if (dp[i][j] != -1)
    return dp[i][j];
  dp[i][j] = INT_MAX;
  for (int k = i; k < j; k++) {
    dp[i][j] = min(dp[i][j], MatrixChainMultiplication(arr, i, k) +
                                 MatrixChainMultiplication(arr, k + 1, j) +
                                 arr[i - 1] * arr[k] * arr[j]);
  }
  return dp[i][j];
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int i = 1;
  int j = n - 1;
  cout << MatrixChainMultiplication(arr, i, j);
  return 0;
}
