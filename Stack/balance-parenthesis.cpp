#include <bits/stdc++.h>
using namespace std;

/*===========Your Code Here=============*/
bool ArePair(char open, char close) {
  if (open == '{' && close == '}')
    return true;
  if (open == '[' && close == ']')
    return true;
  if (open == '(' && close == ')')
    return true;
  return false;
}

bool BalanceParenthesis(string str) {
  stack<char> s;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '[' || str[i] == '{' || str[i] == '(')
      s.push(str[i]);
    if (str[i] == ']' || str[i] == '}' || str[i] == ')') {
      if (s.empty() || !ArePair(s.top(), str[i]))
        return false;
      else
        s.pop();
    }
  }
  s.empty() ? true : false;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  // BalanceParenthesis(str);
  if (!BalanceParenthesis(str))
    cout << "Balanced";
  else
    cout << "Not Balanced";
  cout << endl;
  return 0;
}
