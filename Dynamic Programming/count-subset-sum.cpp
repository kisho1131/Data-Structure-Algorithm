#include <bits/stdc++.h>
using namespace std;

int CountSubset(int arr[], int n, int sum) {
  // int count = 0;
  int dp[n + 1][sum + 1];
  for (int i = 0; i < sum + 1; i++)
    dp[0][i] = 0;
  for (int i = 0; i < n + 1; i++)
    dp[i][0] = 1;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - arr[i - 1]];
      } else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int sum = 4;
  cout << CountSubset(arr, n, sum);
  return 0;
}
