#include <bits/stdc++.h>
using namespace std;

string frequencySort(string s) {
  string ans = "";
  unordered_map<char, int> mp;
  for (char ch : s)
    mp[ch]++;
  priority_queue<pair<int, char>> pq;
  for (auto ele : mp) {
    pq.push({ele.second, ele.first});
  }
  while (!pq.empty()) {
    int freq = pq.top().first;
    for (int i = 0; i < freq; i++)
      ans += pq.top().second;
    pq.pop();
  }
  return ans;
}

int main(int argc, char const *argv[]) {
  string str = "aldmshaaahsdbsdh";
  string ans = frequencySort(str);
  cout << ans;
  return 0;
}
