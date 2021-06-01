#include <bits/stdc++.h>
using namespace std;
#define v 4
#define INF 99999

void printSolution(int dist[][v]) {
  cout << "The following matrix shows the shortest distances"
          " between every pair of vertices \n";
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      if (dist[i][j] == INF)
        cout << "INF"
             << "  ";
      else
        cout << dist[i][j] << "    ";
    }
    cout << endl;
  }
}

void FloydWarshall(int graph[][v]) {
  int dist[v][v];
  for (int i = 0; i < v; i++)
    for (int j = 0; j < v; j++)
      dist[i][j] = graph[i][j];

  for (int k = 0; k < v; k++) {
    for (int i = 0; i < v; i++) {
      for (int j = 0; j < v; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j])
          dist[i][j] = dist[i][k] + dist[k][j];
      }
    }
  }
  printSolution(dist);
}

int main(int argc, char const *argv[]) {

  /* Let us create the following weighted graph
            10
    (0)------->(3)
        |     /|\
    5 |     |
        |     | 1
    \|/     |
    (1)------->(2)
            3     */
  int graph[v][v] = {
      {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF, 0}};

  FloydWarshall(graph);
  return 0;
}
