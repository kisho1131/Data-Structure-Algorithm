/*
Generate all binary strings without consecutive 1’s Given an integer K. Task is
Print All binary string of size K (Given number). Examples
*/

#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void generateAllStringsUtil(int K, char str[], int n) {
  if (n == K) {
    str[n] = '\0';
    cout << str << " ";
    cout << endl;
    return;
  }
  if (str[n - 1] == '1') {
    str[n] = '0';
    generateAllStringsUtil(K, str, n + 1);
  }
  if (str[n - 1] == '0') {
    str[n] = '0';
    generateAllStringsUtil(K, str, n + 1);
    str[n] = '1';
    generateAllStringsUtil(K, str, n + 1);
  }
}

void generateAllStrings(int K) {
  if (K <= 0)
    return;
  char str[K];
  str[0] = '0';
  generateAllStringsUtil(K, str, 1);
  str[0] = '1';
  generateAllStringsUtil(K, str, 1);
}

/*============ Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  generateAllStrings(n);
  cout << endl;
  return 0;
}
