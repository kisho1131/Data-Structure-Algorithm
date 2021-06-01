#include <bits/stdc++.h>
using namespace std;

vector<string> code = {".;",  "abc",  "def", "ghi", "kl",
                       "mno", "pqrs", "tu",  "vw",  "xyz"};

vector<string> keyPad(string str) {
  if (str.length() == 0) {
    vector<string> v;
    v.push_back("");
    return v;
  }
  char ch = str[0];
  string ros = str.substr(1);
  vector<string> recr = keyPad(ros);
  vector<string> res;
  string codech = code[ch - '0'];
  for (int i = 0; i < codech.length(); i++) {
    char ch = codech[i];
    for (auto x : recr)
      res.push_back(ch + x);
  }
  return res;
}

int main(int argc, char const *argv[]) {
  string str = "456";
  vector<string> res = keyPad(str);
  for (auto ptr : res) {
    cout << "[" << ptr << "] ";
  }
  return 0;
}
