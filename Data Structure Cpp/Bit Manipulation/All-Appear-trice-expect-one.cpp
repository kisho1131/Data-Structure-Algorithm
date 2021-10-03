#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }

  unordered_map<int, int>mp;
  for(int i=0;i<n;i++){
    mp[arr[i]]++;
  }
  for(auto x: mp){
    if(x.second ==1){
      cout<<x.first;
    }
  }

  return 0;
}
