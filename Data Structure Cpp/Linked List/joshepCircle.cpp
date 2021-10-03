#include<bits/stdc++.h>
using namespace std;

int JoshepCircle(int n ,int k){
    if(n==1)
        return 1;
    else
        return (JoshepCircle(n-1, k)+ k-1)%n+1;
}

int main(int argc, char const *argv[])
{
    int n = 70;
    int k = 71;
    cout << "The chosen place is " << JoshepCircle(n, k);
    return 0;
}
