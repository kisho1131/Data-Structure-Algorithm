#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
vector<int> graph[1000];

void BFS(int s, int V) {
  list<int> q;
  bool *visited = new bool[V];
  memset(visited, false, sizeof(visited));
  visited[s] = true;
  // list<int>::iterator i;
  q.push_back(s);
  while (!q.empty()) {
    int s = q.front();
    cout << s << " ";
    q.pop_front();
    for (auto it : graph[s]) {
      if (!visited[it]) {
        q.push_back(it);
        visited[it] = true;
      }
    }
  }
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int V, E;
  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }
  BFS(1, V);
  cout << endl;
  return 0;
}
