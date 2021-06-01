#include <bits/stdc++.h>
using namespace std;

int MinSubsetSumDifference(int arr[], int n, int sum) {
  int range = sum;
  bool dp[n + 1][sum + 1];
  int mn = INT_MAX;
  for (int i = 0; i < n + 1; i++)
    dp[i][0] = true;
  for (int i = 0; i < sum + 1; i++)
    dp[0][i] = false;
  vector<int> v;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < sum + 1; j++) {
      if (arr[i - 1] <= j) {
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
      } else
        dp[i][j] = dp[i - 1][j];
    }
  }
  for (int i = sum / 2; i >= 0; i--) {
    if (dp[n][i] == true) {
      v.push_back(i);
    }
  }
  for (int i = 0; i < v.size(); i++) {
    mn = min(mn, range - 2 * v[i]);
  }
  return mn;
}

int main(int argc, char const *argv[]) {
  int arr[] = {3, 1, 4, 2, 2, 1};
  int sum = 0;
  int n = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < n; i++) {
    sum += arr[i];
  }
  cout << MinSubsetSumDifference(arr, n, sum);
  return 0;
}
