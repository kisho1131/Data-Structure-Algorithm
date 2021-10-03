//Program to cyclically rotate the array - clockwise rotation of the array

#include<bits/stdc++.h>
using namespace std;

void clockRotate(int arr[], int n){
int x = arr[n - 1], i;
    for (i = n - 1; i > 0; i--)
    arr[i] = arr[i - 1];
    arr[0] = x;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr) / sizeof(arr[0]);
    clockRotate(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
