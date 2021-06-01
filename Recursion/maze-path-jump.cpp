#include <bits/stdc++.h>
using namespace std;
vector<string> mazePathJumps(int n, int m, int i, int j) {
  if (i == n - 1 && j == m - 1) {
    vector<string> mypath;
    mypath.push_back("");
    return mypath;
  }

  vector<string> paths;
  // Horizontal Moves
  for (int col = 1; col <= m - j; col++) {
    vector<string> hpaths;
    hpaths = mazePathJumps(n, m, i, j + col);
    for (auto hpath : hpaths)
      paths.push_back("H" + hpath + to_string(col));
  }

  // Vertical Moves
  for (int row = 1; row <= n - i; row++) {
    vector<string> vpaths;
    vpaths = mazePathJumps(n, m, i + row, j);
    for (auto vpath : vpaths) {
      paths.push_back("V" + vpath + to_string(row));
    }
  }
  return paths;
}

int main(int argc, char const *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<string> paths = mazePathJumps(n, m, 0, 0);
  for (auto path : paths) {
    cout << "[" << path << "] ";
  }
  return 0;
}
