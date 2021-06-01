#include <bits/stdc++.h>
using namespace std;
int t[100][100];

int KnapSack_Tp(int wt[], int val[], int w, int n) {
  int dp[n + 1][w + 1];
  for (int i = 0; i < n + 1; i++) {
    for (int j = 0; j < w + 1; j++) {
      if (j == 0 || i == 0)
        dp[i][j] = 0;
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < w + 1; j++) {
      if (wt[i - 1] <= j) {
        dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
      } else
        dp[i][j] = dp[i - 1][j];
    }
  }
  return dp[n][w];
}

int KnapSack(int wt[], int val[], int w, int n) {
  if (n == 0 || w == 0)
    return 0;
  if (t[n][w] != -1)
    return t[n][w];
  if (wt[n - 1] <= w) {
    t[n][w] = max(val[n - 1] + KnapSack(wt, val, w - wt[n - 1], n - 1),
                  KnapSack(wt, val, w, n - 1));
    return t[n][w];
  } else {
    t[n][w] = KnapSack(wt, val, w, n - 1);
    return t[n][w];
  }
}

int main(int argc, char const *argv[]) {
  memset(t, -1, sizeof(t));
  int val[] = {60, 100, 120};
  int wt[] = {10, 20, 30};
  int n = sizeof(wt) / sizeof(wt[0]);
  int w = 50;
  int res = KnapSack(wt, val, w, n);
  int restp = KnapSack_Tp(wt, val, w, n);
  cout << "Profit in Topdown: " << restp << endl;
  cout << "Maximum Profit: " << res;
  return 0;
}
