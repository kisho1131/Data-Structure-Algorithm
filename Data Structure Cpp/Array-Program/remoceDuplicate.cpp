#include<bits/stdc++.h>
using namespace std;

void removeDuplicate(char arr[]){
    int len = strlen(arr);
    int prev = 0;
    if(len==0||len==1)
        return;
    for(int i=1; i<len; i++){
        if(arr[i] != arr[prev]){
            prev++;
            arr[prev] = arr[i];
        }
    }
    arr[prev+1] = '\0';
}
int main(int argc, char const *argv[])
{
    char ch[1000];
    cin>>ch;
    removeDuplicate(ch);
    cout<<ch;
    return 0;
}

