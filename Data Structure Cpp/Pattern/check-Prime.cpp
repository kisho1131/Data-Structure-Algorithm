#include<bits/stdc++.h>
using namespace std;


bool checkPrime(int n){
  for(int i=2;i<sqrt(n);i++){
    if(n % i == 0)
      return false;
  }
  return true;
}
int main(int argc, char const *argv[]) {

  int n;
  cin>>n;
  if(checkPrime(n))
    cout<<"True";
  else
    cout<<"False";
  return 0;
}
