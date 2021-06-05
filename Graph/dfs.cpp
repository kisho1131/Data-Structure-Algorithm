#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
vector<int> graph[1000];

void DFS(int start, vector<bool> &visited) {
  visited[start] = true;
  cout << start << " ";
  for (int i = 0; i < graph[start].size(); i++) {
    if (visited[graph[start][i]] == false)
      DFS(graph[start][i], visited);
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int v, e;
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  vector<bool> visited(v);
  for (int i = 0; i < v; i++)
    visited[i] = false;
  int s;
  cin >> s;
  DFS(s, visited);
  cout << endl;
  return 0;
}
