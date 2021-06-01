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

int main(int argc, char const *argv[]) {
  int arr[] = {2, 3, 5, 8, 10};
  int n = sizeof(arr) / sizeof(arr[0]);
  int sum = 10;
  if (SubsetSum(arr, n, sum) == true) {
    cout << "True";
  } else
    cout << "False";
  return 0;
}
