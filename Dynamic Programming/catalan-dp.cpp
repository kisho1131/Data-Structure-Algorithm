#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int CatalanDP(int n) {
  int dp[n + 1];
  dp[0] = dp[1] = 1;
  for (int i = 2; i <= n; i++) {
    dp[i] = 0;
    for (int j = 0; j < i; j++) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }
  return dp[n];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  cout << CatalanDP(n);
  cout << endl;
  return 0;
}
