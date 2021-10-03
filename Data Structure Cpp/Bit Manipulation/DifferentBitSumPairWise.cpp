#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {

  int n,k;
  cin>>n>>k;
  int xxor = 0;
  xxor = n ^ k;
  cout<<__builtin_popcount(xxor);
  return 0;
}
