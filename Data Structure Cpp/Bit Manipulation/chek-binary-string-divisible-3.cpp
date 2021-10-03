#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[]) {
  string s;
  int even =0 ;
  int odd=0;
  cin>>s;
  for(int i=0;i<s.length();i++){
    int bit = s.at(i) - '0'; // substraction by '0' to get the integer value;
    if(i%2==0){
      even += bit;
    }else{
      odd+=bit;
    }
  }

  int delta = (even - odd);
  if(delta % 11 == 0){
    cout<<"true";
  }
  else{
    cout<<"false";
  }
  return 0;
}
