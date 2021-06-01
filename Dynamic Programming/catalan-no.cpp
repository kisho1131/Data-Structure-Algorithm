#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int CalculateCalatan(int n) {
  int sum = 0;
  if (n <= 1)
    return 1;
  for (int i = 0; i < n; i++) {
    sum += CalculateCalatan(i) * CalculateCalatan(n - i - 1);
  }
  return sum;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  cout << CalculateCalatan(n) << " ";
  cout << endl;
  return 0;
}
