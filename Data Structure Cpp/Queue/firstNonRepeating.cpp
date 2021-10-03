#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

int main(int argc, char const *argv[])
{
    queue<char> q;
    char ch;
    unordered_map<char,int> mp;
    cin>>ch;
    while(ch == '.'){
        q.push(ch);
        mp[ch]++;
        while(!q.empty()){
            if(mp[q.front()>1])
                q.pop();
            else{
                cout<<q.front()<<endl;
                break;}
        }
        if(q.empty())
            cout<<"-1"<<endl;
    }
    return 0;
}
