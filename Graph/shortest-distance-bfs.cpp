#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
class graph {
  int V;
  list<int> *g;

public:
  graph(int v) {
    V = v;
    g = new list<int>[V];
  }
  void addEdge(int u, int v, bool directed = true) {
    g[u].push_back(v);
    if (directed)
      g[v].push_back(u);
  }

  void bfs(int start) {
    bool *visited = new bool[V]{0};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty()) {
      int nodes = q.front();
      cout << nodes << " ";
      q.pop();
      for (auto node : g[nodes]) {
        if (!visited[node]) {
          q.push(node);
          visited[node] = true;
        }
      }
    }
  }

  void ShortestPathBFS(int start, int dest = -1) {
    bool *visited = new bool[V]{0};
    int *parent = new int[V]{-1};
    int *dist = new int[V]{0};
    queue<int> q;
    q.push(start);
    visited[start] = true;
    parent[start] = start;
    dist[start] = 0;
    while (!q.empty()) {
      int nodes = q.front();
      // cout << nodes << " ";
      q.pop();
      // Push the nbrs of the current node if they are not yet visited
      for (auto node : g[nodes]) {
        if (!visited[node]) {
          q.push(node);
          parent[node] = nodes;
          dist[node] = dist[nodes] + 1;
          visited[node] = true;
        }
      }
    }
    for (int i = 0; i < V; i++) {
      cout << "Shortest Distance to " << i << " is " << dist[i] << endl;
    }
    // Printing the shortest path from source to destination
    if (dest != -1) {
      int temp = dest;
      while (temp != start) {
        cout << temp << "-->";
        temp = parent[temp];
      }
      cout << start << endl;
    }
  }
};

// Single source shortest path f
/*============Main()====================*/
int main(int argc, char const *argv[]) {
  graph g(6);
  g.addEdge(0, 1);
  g.addEdge(0, 4);
  g.addEdge(2, 1);
  g.addEdge(3, 4);
  g.addEdge(4, 5);
  g.addEdge(2, 3);
  g.addEdge(3, 5);
  g.ShortestPathBFS(1, 5);
  return 0;
}
