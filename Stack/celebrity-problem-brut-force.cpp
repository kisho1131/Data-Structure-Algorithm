#include <bits/stdc++.h>
using namespace std;
#define N 8
bool MATRIX[N][N] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};

/*===========Your Code Here=============*/
int knows(int a, int b) { return MATRIX[a][b]; }
int FindCelebrity(int n) {
  int inDegree[n] = {0};
  int outDegree[n] = {0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int x = knows(i, j);
      inDegree[j] += x;
      outDegree[i] += x;
    }
  }
  for (int i = 0; i < n; i++) {
    if (inDegree[i] == n - 1 && outDegree[i] == 0)
      return i;
  }
  return -1;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n = 4;
  int res = FindCelebrity(n);
  if (res != -1)
    cout << res;
  else
    cout << "No Celebrity";
  cout << endl;
  return 0;
}
