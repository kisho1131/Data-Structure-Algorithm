#include<bits/stdc++.h>
#include<climits>
using namespace std;

void LeftRotate(int arr[], int n , int k){
    for(int i =k; i<k+n; i++){
        cout<<arr[i%n]<<" ";
    }
}

int main(int argc, char const *argv[])
{
    int num;
    int k;
    int arr[INT_MAX];
    cin>>num>>k;
    for(int i=0; i<num; i++){
        cin>>arr[i];
    }
    LeftRotate(arr, num, k);
    return 0;
}
