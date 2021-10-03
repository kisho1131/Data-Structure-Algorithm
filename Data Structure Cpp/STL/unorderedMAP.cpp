#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  string str = "lets greek for greek in doing greek for great great things greek";
  unordered_map<string, int> mp;
  stringstream ss(str); // Used for breaking the sentence into words::)
  string word;
  while(ss >> word){
    mp[word]++;
  }

  for(auto it = mp.begin(); it!=mp.end(); it++){
    cout<<it->first<<"-->"<<it->second<<endl;
  }
  return 0;
}
