/*
Generate All the String from the given Pattern
*/

#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void GeneratePattern(string str, int idx) {
  if (idx == str.size()) {
    cout << str << " ";
    cout << endl;
    return;
  }
  if (str[idx] == '?') {
    str[idx] = '0';
    GeneratePattern(str, idx + 1);
    str[idx] = '1';
    GeneratePattern(str, idx + 1);
  } else
    GeneratePattern(str, idx + 1);
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  string str;
  cin >> str;
  GeneratePattern(str, 0);
  cout << endl;
  return 0;
}
