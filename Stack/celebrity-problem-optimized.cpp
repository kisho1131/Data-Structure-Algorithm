#include <bits/stdc++.h>
using namespace std;
#define N 8
int MATRIX[N][N] = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};

/*===========Your Code Here=============*/
//  bool knows(int a, int b) { return MATRIX[a][b]; }

void CelebrityProblem(int n) {
  stack<int> st;
  for (int i = 0; i < n; i++)
    st.push(i);
  while (st.size() > 1) {
    int a = st.top();
    st.pop();
    int b = st.top();
    st.pop();
    if (MATRIX[a][b] == 1)
      st.push(b);
    else
      st.push(a);
  }
  int pot = st.top();
  st.pop();
  for (int i = 0; i < n; i++) {
    if (i != pot && MATRIX[i][pot] == 0 || MATRIX[pot][i] == 1) {
      /* if there is any i who dont know the potential Celebrity */
      cout << " No Celebrity";
      return;
    }
  }
  cout << pot;
}

/*============Main()====================*/
int main(int argc, char const *argv[]) {
  int n = 4;
  CelebrityProblem(n);
  cout << endl;
  return 0;
}
