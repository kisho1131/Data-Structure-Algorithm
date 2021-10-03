#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int res = 0;
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  for(auto val:arr){
    res = res^(2*val);
  }
  cout<<res;
  return 0;
}
