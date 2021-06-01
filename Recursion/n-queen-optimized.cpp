#include <bits/stdc++.h>
using namespace std;
bitset<100> col, ld, rd;
/*===========Your Code Here=============*/
int Qcount = 0;
void NQueenBitMask(int n, int cr) {
  if (cr == n) {
    Qcount++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!col[i] and !ld[cr - i + n - 1] and !rd[cr + i]) {
      col[i] = ld[cr - i + n - 1] = rd[cr + i] = 1;
      NQueenBitMask(n, cr + 1);
      col[i] = ld[cr - i + n - 1] = rd[cr + i] = 0;
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  NQueenBitMask(n, 0);
  cout << endl;
  cout << Qcount;
  cout << endl;
  return 0;
}
