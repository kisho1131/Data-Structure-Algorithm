#include <bits/stdc++.h>
using namespace std;
int ans = 0;
/*===========Your Code Here=============*/
bool isSafeState(vector<vector<bool>> &grid, int r, int c, int n) {
  if (r - 2 >= 0 and c - 1 >= 0 and grid[r - 2][c - 1])
    return false;
  if (r - 1 >= 0 and c - 2 >= 0 and grid[r - 1][c - 2])
    return false;
  if (r - 2 >= 0 and c + 1 < n and grid[r - 2][c + 1])
    return false;
  if (r - 1 >= 0 and c + 2 < n and grid[r - 1][c + 2])
    return false;
  return true;
}
void Nknights(vector<vector<bool>> &grid, int cr, int cc, int ct, int n) {
  if (ct == n) {
    ans++;
    return;
  }
  // Outer loop start from the cr not from 0 as for the recursive call we have
  // to start from that row
  for (int i = cr; i < n; i++) {
    for (int j = (i == cr) ? cc : 0; j < n; j++) {
      if (isSafeState(grid, i, j, n)) {
        grid[i][j] = true;
        Nknights(grid, i, j + 1, ct + 1, n);
        grid[i][j] = false;
      }
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<vector<bool>> grid(n, vector<bool>(n, false));
  Nknights(grid, 0, 0, 0, n);
  cout << ans;
  cout << endl;
  return 0;
}
