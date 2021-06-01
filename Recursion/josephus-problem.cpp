#include <bits/stdc++.h>
using namespace std;

void solve(std::vector<int> v, int index, int k, int &ans) {
  if (v.size() == 1) {
    ans = v[0];
    return;
  }
  index = (index + k) % v.size();
  v.erase(v.begin() + index);
  solve(v, index, k, ans);
}

int main(int argc, char const *argv[]) {
  int n, k;
  cin >> n;
  cin >> k;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    v.push_back(num);
  }
  k = k - 1;
  int index = 0;
  int ans = -1;
  solve(v, index, k, ans);
  cout << ans;
  return 0;
}
