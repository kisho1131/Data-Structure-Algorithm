
// Question
// 1. You are given two numbers A and B.
// 2. You are given two more numbers left and right, representing a range [left,right].
// 3. You have to set bits in B which are set in A lying in the above mentioned range.
// 4. Print the updated number B.

#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, l, r;
    cin>>a>>b>>l>>r;
    int mask = (1<<(r-l+1));
    mask--;
    mask = mask<<(l-1);
    mask = (mask & a);
    b = b | mask;
    cout<<b;
    return 0;
}
