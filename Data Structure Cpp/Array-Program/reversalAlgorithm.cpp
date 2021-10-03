//Reversal Algorithm for the rotation of array

#include<bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)

void reverseArray(int arr[], int start, int end){
    while(start < end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void leftRotate(int arr[], int n, int d){
    if (d==0)
        return;
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}
int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,12,13,14};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 4;
    leftRotate(arr, n, d);
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<"->";
    return 0;
}
