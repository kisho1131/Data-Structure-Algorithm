#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  long int n;
  cin>>n;
  vector<long int> v;
  vector<long int>ans;
  for(int i=0;i<n;i++){
    int num;
    cin>>num;
    v.push_back(num);
  }
  for(int i=0;i<n;i++){
    for(int j = 0; j<n;j++){
      long int xxor = v[i] ^ v[j];
      ans.push_back(__builtin_popcount(xxor));
    }
  }
  long int sum = 0;
  for(auto x : ans){
    sum += x;
  }
  cout<<sum;
  return 0;
}
