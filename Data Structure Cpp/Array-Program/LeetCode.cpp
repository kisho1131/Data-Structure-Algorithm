#include<bits/stdc++.h>
using namespace std;
void duplicateZero(int arr[], int n){
    for(int i=0; i<n; i++){
        if(arr[i]==0)
            arr[(i+1)] = 0;
    }
}
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i] <<" ";
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,0,2,3,9,4,5,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    cout<<endl;
    duplicateZero(arr, n);
    printArray(arr, n);
    return 0;
}
