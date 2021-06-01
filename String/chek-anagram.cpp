#include <bits/stdc++.h>
using namespace std;

bool CheckAnagram(string s1, string s2) {
  int l1 = s1.length();
  int l2 = s2.length();
  if (l1 != l2) {
    return false;
  }
  int count[256] = {0};
  for (int i = 0; i < l1; i++) {
    count[s1[i]]++;
  }
  for (int i = 0; i < s2.length(); i++) {
    count[s2[i]]--;
  }

  for (int i = 0; i < 256; i++) {
    if (count[i] != 0)
      return false;
  }
  return true;
}

int main(int argc, char const *argv[]) {

  string s1;
  string s2;
  cin >> s1;
  cin >> s2;
  bool ans = CheckAnagram(s1, s2);
  if (ans) {
    cout << "True";
  } else
    cout << "False";
  return 0;
}
