#include <bits/stdc++.h>
using namespace std;
int totalPath = 0;
void mazePath(int n, int m, int i, int j, string osf) {
  if (i == n - 1 && j == m - 1) {
    totalPath++;
    // cout << osf << " ";
    return;
  }
  if (i >= n || j >= m)
    return;
  mazePath(n, m, i + 1, j, osf + "D");
  mazePath(n, m, i, j + 1, osf + "R");
}

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  int i = 0, j = 0;
  string osf = "";
  mazePath(n, m, i, j, osf);
  cout << totalPath;
  return 0;
}
