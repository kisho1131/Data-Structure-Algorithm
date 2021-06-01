#include <bits/stdc++.h>
using namespace std;

int CountSubsetSum(int arr[], int n, int sum) {
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

int CountNoOfSubset(int arr[], int n, int diff) {
  int sum = 0;
  for (int i = 0; i < n; i++)
    sum += arr[i];
  int subset = (diff + sum) / 2;
  // cout << subset << endl;
  return CountSubsetSum(arr, n, subset);
}

int main(int argc, char const *argv[]) {
  int arr[] = {1, 1, 2, 3};
  int n = sizeof(arr) / sizeof(arr[0]);
  int diff = 1;
  cout << CountNoOfSubset(arr, n, diff);
  return 0;
}
