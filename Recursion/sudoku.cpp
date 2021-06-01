#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
void displayGrid(vector<vector<int>> &grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}
bool isValid(vector<vector<int>> &grid, int x, int y, int val, int n) {
  for (int j = 0; j < n; j++)
    if (grid[x][j] == val)
      return false;
  for (int i = 0; i < n; i++)
    if (grid[i][y] == val)
      return false;
  int subi = x / 3 * 3;
  int subj = y / 3 * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (grid[subi + i][subj + j] == val)
        return false;
    }
  }
  return true;
}
void Sudoku(vector<vector<int>> &grid, int row, int col, int n) {
  if (row == n) {
    displayGrid(grid, n);
    return;
  }
  int nrow = 0;
  int ncol = 0;
  if (col == n) {
    nrow = row + 1;
    ncol = 0;
  } else {
    nrow = row;
    ncol = col + 1;
  }
  if (grid[row][col] != 0) {
    Sudoku(grid, nrow, ncol, n);
  } else {
    for (int po = 1; po <= 9; po++) {
      if (isValid(grid, row, col, po, n)) {
        grid[row][col] = po;
        Sudoku(grid, nrow, ncol, n);
        grid[row][col] = 0;
      }
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  // int n;
  // cin >> n;
  int n = 9;
  vector<vector<int>> grid(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }
  cout << endl;
  Sudoku(grid, 0, 0, n);
  cout << endl;
  return 0;
}
