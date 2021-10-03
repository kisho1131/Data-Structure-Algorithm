#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  char s1[100], s2[100], s3[100];
  cin>>s1>>s2>>s3;
  for(int i=0;i<strlen(s1);i++){
    if(s1[i] == 'a' || s1[i] == 'e' || s1[i] == 'i' || s1[i] =='o' || s1[i] == 'u')
      s1[i] = '%';
  }
  for(int i=0;i<strlen(s2);i++){
    if(s2[i] == 'a' || s2[i] == 'e' || s2[i] == 'i' || s2[i] =='o' || s2[i] == 'u')
      s2[i] = s2[i];
    else
      s2[i] = '#';
  }
  for(int i=0;i<strlen(s3);i++){
    s3[i] = toupper(s3[i]);
  }
  cout<<s1<<s2<<s3;
  return 0;
}
