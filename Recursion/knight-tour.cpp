#include <bits/stdc++.h>
using namespace std;
// int count = 0;
/*===========Your Code Here=============*/
void Display(vector<vector<int>> &grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; i < n; j++)
      cout << grid[i][j];
  }
}

bool isItSafe(vector<vector<int>> &grid, int row, int col, int n,
              vector<vector<bool>> &visited) {
  return (row >= 0 and col >= 0 and row < n and col < n and
          visited[row][col] == false);
}

void knightTour(vector<vector<int>> &grid, int row, int col, int n, int count,
                vector<vector<bool>> &visited) {
  if (count == n * n - 1) {
    grid[row][col] = count;
    Display(grid, n);
    cout << endl;
    return;
  }
  if (count >= n * n)
    return;

  int xdir[8] = {-2, -2, -1, -1, 2, 2, 1, 1};
  int ydir[8] = {1, -1, 2, -2, 1, -1, 2, -2};
  visited[row][col] = true;
  grid[row][col] = count;
  for (int i = 0; i < 8; i++) {
    if (isItSafe(grid, row + xdir[i], col + ydir[i], n, visited)) {
      knightTour(grid, row + xdir[i], col + ydir[i], n, count + 1, visited);
    }
  }
  grid[row][col] = -1;
  visited[row][col] = false;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n;
  cin >> n;
  vector<vector<int>> grid(n, vector<int>(n, -1));
  vector<vector<bool>> visited(n, vector<bool>(n, false));
  knightTour(grid, 0, 0, n, 0, visited);
  cout << endl;
  return 0;
}
