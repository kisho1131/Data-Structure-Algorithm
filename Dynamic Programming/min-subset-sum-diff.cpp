#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDiff(int arr[], int n) {
  int sum = 0;
  vector<int> res;
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  bool dp[n + 1][sum + 1];
  for (int i = 0; i < sum + 1; i++)
    dp[0][i] = false;
  for (int i = 0; i < n + 1; i++)
    dp[i][0] = true;
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < sum + 1; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      } else
        dp[i][j] = dp[i - 1][j];
    }
  }
  int diff = INT_MAX;
  // Find the largest j such that dp[n][j]
  // is true where j loops from sum/2 t0 0
  for (int j = sum / 2; j >= 0; j--) {
    if (dp[n][j] == true) {
      diff = sum - 2 * j;
      break;
    }
  }
  return diff;
}

int main(int argc, char const *argv[]) {

  int arr[1000];
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int res = minSubsetSumDiff(arr, n);
  cout << res;
  return 0;
}
