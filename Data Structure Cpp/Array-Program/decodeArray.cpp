#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void Decode(int arr[], int n){
    for(int i = n-2;i>=0;i--){
        arr[i] = arr[i] - arr[i+1];
    }
    printArray(arr, n);
}

int main(int argc, char const *argv[])
{
    int arr[] = { 7,6,8,16,12,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<n;
    cout<<endl;
    Decode(arr, n);
    return 0;
}
