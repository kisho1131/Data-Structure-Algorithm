/* I have two numbers A and B
 *  where A and B can be in the range 1<= A,B <=100^100000
 */

#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
int modular(int base, unsigned int exp, unsigned int mod) {
  int x = 1;
  int i;
  int power = base % mod;

  for (i = 0; i < sizeof(int) * 8; i++) {
    int least_sig_bit = 0x00000001 & (exp >> i);
    if (least_sig_bit)
      x = (x * power) % mod;
    power = (power * power) % mod;
  }
  return x;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int exp;
  cin >> exp;
  int ans = 1;
  for (int i = 2; i < 5; i++) {
    ans += modular(i, exp, 5);
  }
  cout << ans % 5;
  return 0;
}
