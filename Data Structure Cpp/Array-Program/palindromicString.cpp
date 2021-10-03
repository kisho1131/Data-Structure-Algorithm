#include<bits/stdc++.h>
using namespace std;

bool isPalandromic(char ch[]){
    int start = 0;
    int end = strlen(ch)-1;
    while(start < end){
        if(ch[start] == ch[end]){
            start++;
            end--;
        }
        else{
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    char ch[1000];
    cin>>ch;
    if(isPalandromic(ch))
        cout<<"Palandromic";
    else
        cout<<"Not Palandromic";
    return 0;
}

