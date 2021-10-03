#include<bits/stdc++.h>
using namespace std;
int dp[12][12];
int lcs(string s1, string s2, int l1, int l2){

  // memset(dp, -1, sizeof(dp));
  if(dp[l1][l2] == -1){
    if(l1==0 || l2==0)
      dp[l1][l2]=0;
    else if(s1[l1-1] == s2[l2-1])
       dp[l1][l2] =  1 + lcs(s1, s2, l1-1, l2-1);
    else
      dp[l1][l2] =  max(lcs(s1, s2, l1-1, l2), lcs(s1, s2, l1, l2-1));
  }
    return dp[l1][l2];
}

int main(int argc, char const *argv[]) {
  memset(dp, -1, sizeof(dp));
  string s1 = "sumitkumar";
  string s2 = "sumitsdbsbuddsf";
  int l1 = s1.size();
  int l2 = s2.size();
  cout<<lcs(s1, s2, l1, l2);
  return 0;
}
