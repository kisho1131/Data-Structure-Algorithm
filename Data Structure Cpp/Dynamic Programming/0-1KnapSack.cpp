#include <bits/stdc++.h>
using namespace std;
int static t[10][10];

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
  // int W = 50;
  int n = sizeof(wt) / sizeof(wt[0]);
  int w = 50;
  int res = KnapSack(wt, val, w, n);
  cout << "Maximum Profit: " << res;
  return 0;
}
