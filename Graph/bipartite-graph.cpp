#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
bool biPartiteGraph(int src, vector<int> adj[], int color[]) {
  color[src] = 1;
  queue<int> q;
  q.push(src);
  while (!q.empty()) {
    int node = q.front();
    q.pop();
    for (auto it : adj[node]) {
      if (color[it] == -1) {
        color[it] = 1 - color[node];
        q.push(it);
      } else if (color[it] = color[node])
        return false;
    }
  }
  return true;
}

bool checkBipartite(vector<int> adj[], int n) {
  int color[n];
  memset(color, -1, sizeof color);
  for (int i = 0; i < n; i++) {
    if (color[i] == -1) {
      if (!biPartiteGraph(i, adj, color))
        return false;
    }
  }
  return true;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n, e;
  cin >> n >> e;
  vector<int> adj[n];
  for (int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  if (checkBipartite(adj, n))
    cout << "Yes";
  else
    cout << "No";
  cout << endl;
  return 0;
}
