#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {

  int l,h;
  cin>>l>>h;
  int flag;
  while (l<h) {
    if(l==1 || l==0)
     continue;
     flag = 0;
    for(int i=2;i<=l/2;i++){
      if( l % i == 0)
        flag = 1;
    }
    if(flag == 0)
      cout<<l<<" ";
    l++;

  }
  return 0;
}
