#include<bits/stdc++.h>
using namespace std;

int CountOperation(long n){
    int res = 0;
    while(n!=1){
        if(n%2==0)
          n = n/2;
        else if(n==3)
          n = n-1;
        else if((n&3) ==1){
            n = n-1;
        }
        else if((n&3)==3){
            n = n+1;
        }
        res++;
    }
    return res++;
}

int main(){
    int n;
    cin>>n;
    int res = CountOperation(n);
    cout<<res;
    return 0;
}
