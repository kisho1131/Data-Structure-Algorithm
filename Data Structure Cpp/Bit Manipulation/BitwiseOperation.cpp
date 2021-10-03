#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]){
  int n = 20;
  int rmsb = n & -n;
  cout<<rmsb;
  cout<<endl;
  cout<<log2(rmsb) +1;
  return 0;
}
