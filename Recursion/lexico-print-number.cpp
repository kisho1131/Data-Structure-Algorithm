#include <bits/stdc++.h>
using namespace std;

/* ============ Your Code Here ================ */
void Permutation(string str, string prem) {
  if (str.length() == 0) {
    cout << prem << endl;
    return;
  }
  unordered_set<char> s;
  for (int i = 0; i < str.size(); i++) {
    char ch = str[i];
    if (s.count(ch) == 0) { // => Handle the Duplicate Conditation
      string res = str.substr(0, i) + str.substr(i + 1);
      // Subtring --> O(N)
      s.insert(ch);
      Permutation(res, prem + ch);
    }
  }
}

void lexico(int n, int i) {
  if (n < i)
    return;
  cout << i << endl;
  for (int j = (i == 0) ? 1 : 0; j <= 9; j++)
    lexico(n, 10 * i + j);
}

int main(int argc, char const *argv[]) {
  Permutation("ABB", "");
  return 0;
}
