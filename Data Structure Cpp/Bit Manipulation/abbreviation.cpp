#include<bits/stdc++.h>
using namespace std;

void abbreviation(string str){
//   char ans[100000];
string ans;
  int count = 0;
  for(int i=0;i<(1<<str.length());i++){
    // char ch = str.at(j);
    for(int j=0;j<str.length();j++){
      char ch = str.at(j);
      int bit = str.length()-1-j;
      if(i & (1<<bit)==0){
        if(count==0){
          ans.append(ch);
        }else{
          ans.append(count);
          ans.append(ch);
          count = 0;
        }
      }else{
        count++;
      }
    }
    if(count > 0){
      ans.append(count);
    }
  }
  cout<<ans;

}
int main(int argc, char const *argv[]) {

  string str;
  cin>>str;
  abbreviation(str);
  return 0;
}
