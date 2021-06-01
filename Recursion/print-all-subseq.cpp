#include <bits/stdc++.h>
using namespace std;

vector<string> printSubseq(string str) {
  if (str.length() == 0) {
    vector<string> resvec;
    resvec.push_back("");
    return resvec;
  }
  char ch = str[0];
  string rof = str.substr(1);
  vector<string> resc = printSubseq(rof);
  vector<string> resvec;
  for (auto x : resc) {
    resvec.push_back(x + "_");
    resvec.push_back(x + ch);
  }
  return resvec;
}

void printSequence(string str, string ans) {
  if (str.length() == 0) {
    cout << "[" << ans << "] ";
    return;
  }

  char ch = str[0];
  string ros = str.substr(1);
  printSequence(ros, ch + ans);
  printSequence(ros, ans + "_");
}

int main(int argc, char const *argv[]) {
  string str = "abc";
  vector<string> res = printSubseq(str);
  for (auto str : res) {
    cout << "[" << str << "] ";
  }
  cout << endl;
  printSequence(str, "");
  cout << endl;
  return 0;
}
