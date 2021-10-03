#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int>adj[], int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

void DFSrec(vector<int>adj[], int s, bool visited[]){
  visited[s] = true;
  cout<<s<<"-->";
  for(auto v:adj[s]){
    if(visited[v] == false)
      DFSrec(adj, v, visited);
  }
}

void DFS(vector<int>adj[], int v, int s){
  bool visited[v+1];
  for(int i=0;i<v;i++)
     visited[i] = false;
  DFSrec(adj, s, visited);
}
int main(int argc, char const *argv[]) {

// 2 -> 0, 0 -> 2, 1 -> 2, 0 -> 1, 3 -> 3, 1 -> 3
  int V = 4;
  vector<int> adj[V];
    addEdge(adj, 2, 0);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 3, 3);
    addEdge(adj, 1, 3);
  //   addEdge(adj, 3, 4);
    cout<<endl;
    cout<<"DFS ";
    DFS(adj, V, 2);
  return 0;
}
