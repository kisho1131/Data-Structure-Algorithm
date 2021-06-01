#include <bits/stdc++.h>
using namespace std;

int queenCount = 0;
void Display(vector<vector<bool>> &grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (grid[i][j] == true)
        cout << "Q ";
      else
        cout << ". ";
    }
    cout << endl;
  }
}

bool isItSafe(vector<vector<bool>> &grid, int row, int col, int n) {
  for (int i = row - 1; i >= 0; i--) {
    if (grid[i][col])
      return false;
  }
  // left upper Diagonal
  for (int i = row - 1, j = col - 1; i >= 0 & j >= 0; i--, j--) {
    if (grid[i][j])
      return false;
  }

  // Right Upper Diagonal
  for (int i = row - 1, j = col + 1; i >= 0 & j < n; i--, j++) {
    if (grid[i][j])
      return false;
  }
  return true;
}

void countNQueen(vector<vector<bool>> &grid, int curr_row, int n) {
  if (curr_row == n) {
    queenCount++;
    Display(grid, n);
    cout << endl;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (isItSafe(grid, curr_row, i, n)) {
      grid[curr_row][i] = true;
      countNQueen(grid, curr_row + 1, n);
      grid[curr_row][i] = false;
    }
  }
}

int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<vector<bool>> grid(n, vector<bool>(n, false));
  countNQueen(grid, 0, n);
  // cout << queenCount;
  return 0;
}
