//Reorder an array according to given indexes
//Given two integer arrays of same size, “arr[]” and “index[]”,
//reorder elements in “arr[]” according to given index array.
// It is not allowed to given array arr’s length.

#include<bits/stdc++.h>
using namespace std;

void Reorder(int arr[], int index[], int n){
    int *temp = new int[n+1];
    for(int i=0; i<n; i++){
        temp[index[i]] = arr[i];
    }
    for(int j =0; j<n; j++){
        arr[j] = temp[j];
        index[j] = j;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {50, 40, 70, 60, 90};
    int index[] = {3,  0,  4,  1,  2};
    int n = sizeof(arr)/sizeof(arr[0]);
    Reorder(arr, index, n);
    for(int i = 0; i<n; i++)
        cout<<arr[i]<<"->";
    cout<<endl;
    for(int i = 0; i<n; i++)
        cout<<index[i]<<"->";
    return 0;
}
