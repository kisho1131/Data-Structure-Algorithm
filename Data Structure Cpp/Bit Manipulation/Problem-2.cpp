/*
Kernighans Algorithm
1. You are given a number n.
2. You have to count the number of set bits in the given number.
*/

#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  int n;
  cin>>n;
  //int rmsb;
  int count = 0;
  while(n > 0){
    int rmsb = n & -n;
    n = n - rmsb;
    count++;
  }
//  cout<<endl;
  // string s = bitset<64>(n).to_string();
  // cout<<s;
  // cout<<endl;
  cout<<"Count of 1's is: "<<count;
  cout<<endl;
//  count<<"Count of 0's is: "<<(s.length()-count);
  return 0;
}
