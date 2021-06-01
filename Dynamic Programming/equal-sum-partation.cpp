#include <bits/stdc++.h>
using namespace std;

bool SubsetSum(int arr[], int n, int sum) {
  bool dp[n + 1][sum + 1];
  for (int i = 0; i < n; i++)
    dp[i][0] = true;
  for (int i = 0; i <= sum; i++)
    dp[0][i] = false;

  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
      } else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][sum];
}

bool equalSumPartation(int arr[], int n) {
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum = sum + arr[i];
  }
  if (sum % 2 != 0)
    return false;
  else
    return SubsetSum(arr, n, sum / 2);
}

int main(int argc, char const *argv[]) {
  int arr[] = {5, 5, 1, 11};
  int n = sizeof(arr) / sizeof(arr[0]);
  if (equalSumPartation(arr, n)) {
    cout << "True";
  } else {
    cout << "False";
  }
  return 0;
}
