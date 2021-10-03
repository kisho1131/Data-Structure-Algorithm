#include<iostream>
#include<vector>
using namespace std;

int fibMemo(int n){
  int *memo = new int[n];
  int res = 0;
  for(int i=0;i<n;i++)
     memo[i] = -1;
  if(memo[n] ==-1){
    if(n==0 || n==1)
     res = n;
     else{
    res = fibMemo(n-1) + fibMemo(n-2);
    memo[n] = res;
      }
  }
  return memo[n];
}

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int res = fibMemo(n);
  cout<<res;
  return 0;
}
