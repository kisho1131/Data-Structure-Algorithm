#include <bits/stdc++.h>
using namespace std;

int MatrixChainMultiplication(int p[], int n) {
  int dp[n][n];
  int j, q;
  for (int i = 1; i < n; i++) {
    dp[i][i] = 0;
  }
  for (int l = 2; l < n; l++) {
    for (int i = 1; i < n - l + 1; i++) {
      j = i + l - 1;
      dp[i][j] = INT_MAX;
      for (int k = i; k < j; k++) {
        q = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < dp[i][j])
          dp[i][j] = q;
      }
    }
  }
  return dp[1][n - 1];
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 2, 3, 4, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << MatrixChainMultiplication(arr, n);
  return 0;
}
