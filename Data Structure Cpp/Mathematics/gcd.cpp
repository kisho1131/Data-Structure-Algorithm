#include<bits/stdc++.h>
using namespace std;


int gcd(int a, int b){
  if(b == 0)
     return a;
  return gcd(b, a%b);
}
int main(int argc, char const *argv[]) {

  int n;
  cin>>n;
  int res;
  vector<int>v;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    v.push_back(num);
  }
  res = v[0];
  for(int i=0;i<n;i++){
    res = gcd(res, v[i]);
    if(res == 1){
      return 1;
    }
  }
  cout<<res;
  return 0;
}
