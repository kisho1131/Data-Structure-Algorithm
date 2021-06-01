#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
bool isOperator(char ch) {
  switch (ch) {
  case '+':
  case '-':
  case '*':
  case '/':
    return true;
  }
  return false;
}

string PrefixToPostfix(string str) {
  stack<string> s;
  int n = str.length();
  for (int i = n - 1; i >= 0; i--) {
    if (isOperator(str[i])) {
      string op1 = s.top();
      s.pop();
      string op2 = s.top();
      s.pop();
      string temp = op1 + op2 + str[i];
      s.push(temp);
    } else {
      s.push(string(1, str[i])); /* Fill the string with the n no of given
                                    character syntax string(int n, 'char') */
    }
  }
  return s.top();
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string exp = "*-A/BC-/AKL";
  cout << PrefixToPostfix(exp);
  cout << endl;
  return 0;
}
