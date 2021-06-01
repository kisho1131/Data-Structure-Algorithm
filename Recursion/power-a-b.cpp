#include <bits/stdc++.h>
using namespace std;

long long solution(long long a, long long b) {
  if (b == 0)
    return 1;
  return a * solution(a, b - 1);
}

long long powerLog(long long a, long long b) {
  if (b == 0)
    return 1;
  long long temp = powerLog(a, b / 2);
  if (b % 2 == 0)
    return temp * temp;
  else
    return a * temp * temp;
}

int main(int argc, char const *argv[]) {
  int a, b;
  cin >> a >> b;
  cout << solution(a, b);
  cout << endl;
  cout << "In Log Time: " << powerLog(a, b);
  return 0;
}
