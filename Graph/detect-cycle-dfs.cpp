#include <bits/stdc++.h>
using namespace std;
/*===========Your Code Here=============*/
bool checkForCycle(int node, int parent, vector<int> &visited,
                   vector<int> adj[]) {
  visited[node] = 1;
  for (auto it : ajd[node]) {
    if (visited[it] == 0)
      if (checkForCycle(it, node, visited, adj))
        return true;
      else if (it != parent)
        return true;
  }
  return false;
}

bool isCycle(int V, vector<int> ajd[]) {
  vector<int> visited(0);
  for (int i = 0; i < V; i++) {
    if (!visited[i])
      if (checkForCycle(i, -1, visited, adj))
        return true;
  }
  return false;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {

  cout << endl;
  return 0;
}
