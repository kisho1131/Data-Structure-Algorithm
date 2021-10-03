#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  int n, i;
  cin>>n>>i;
  int a = 1<<i;
  if(a & n == 0)cout<<"false";
  else cout<<"true";
  cout<<endl;
  cout<<__builtin_popcount(n);
  int count = 0;
  int rmsb =  n & -n;
  while(n > 0){
    n = n - rmsb;
    rmsb = n & -n;
    count++;
  }
  cout<<endl;
  cout<<count;
  return 0;
}
