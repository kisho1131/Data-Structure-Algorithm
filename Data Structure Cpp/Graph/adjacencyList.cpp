
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void addEdge(vector<int> adj[], int u, int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}
void printEdge(vector<int>adj[], int v){
  for(int i=0;i<v;i++){
    cout<<"Adjacency List of vertex: "<<i<<" ";
    for(auto x : adj[i])
       cout<<"-->"<<x;
    cout<<endl;
  }
}

void BFS(vector<int>adj[], int v, int s){
  bool visited[v+1];
  for(int i=0;i<v;i++)
     visited[i] = false;
  queue<int>q;
  q.push(s);
  visited[s] = true;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    cout<<u<<" ";
    for(auto x = adj[u].begin(); x!=adj[u].end(); x++){
      if(visited[*x]==false){
        visited[*x] = true;
        q.push(*x);
      }
    }
  }
}

int main(int argc, char const *argv[]) {
  int V = 5;
  vector<int> adj[V];
    addEdge(adj, 0, 1);
    addEdge(adj, 0, 4);
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    printEdge(adj, V);
    cout<<endl;
    cout<<"BFS: ";
    BFS(adj, V, 2);

  return 0;
}
