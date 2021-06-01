#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/

void DistinctSubstring(string str) {
  int n = str.length();
  int dp[n + 1];
  unordered_map<char, int> mp;
  dp[0] = 1;
  for (int i = 1; i <= n; i++) {
    dp[i] = 2 * dp[i - 1];
    char ch = str[i - 1];
    if (mp.find(ch) != mp.end()) {
      int idx = mp.at(ch);
      dp[i] = dp[i] - dp[idx - 1];
    }
    mp.insert({ch, i});
  }
  cout << dp[n];
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  DistinctSubstring(str);
  cout << endl;
  return 0;
}
