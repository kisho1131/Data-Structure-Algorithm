#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n;
  cin>>n;
  int num = 1;
  for(int i= 0;i<n;i++){
    for(int j=1;j<=i;j++){
      cout<<num<<" ";
      num++;
    }
    cout<<endl;
  }
  return 0;
}
