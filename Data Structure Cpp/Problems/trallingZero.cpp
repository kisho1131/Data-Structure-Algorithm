#include<bits/stdc++.h>
using namespace std;

int trallingZero(int num){
    int fact = num;
    int count = 0;
    int i = 1;
    // Find the no.of Occurance of 5
    while(fact!=0){
        fact = num / pow(5, i);
        count += fact;
        i++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int res = trallingZero(100000);
    cout<<res<<endl;
    return 0;
}
