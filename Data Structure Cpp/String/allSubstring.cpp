#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {

  string s;
  cin>>s;
  // len = strlen(s);
  char *arr = new int[s.size()];
  for(int i=0;i<s.size();i++){
    arr[i] = s[i];
  }
  return 0;
}
