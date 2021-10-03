// Given an array of random numbers, Push all the zero’s of a given array to the end of the array.
// Time complexity = O(n) Space Complexity = O(1)
// Using Single Traversal

#include<bits/stdc++.h>
using namespace std;

void pushZerosToEnd(int arr[], int n)
{
    int count = 0;  // Count of non-zero elements

    // Traverse the array. If element encountered is non-
    // zero, then replace the element at index 'count'
    // with this element
    for (int i = 0; i < n; i++)
        if (arr[i] != 0)
            arr[count++] = arr[i];
    // here count is incremented
    // Now all non-zero elements have been shifted to
    // front and  'count' is set as index of first 0.
    // Make all elements 0 from count to end.
    while (count < n)
        arr[count++] = 0;
}

void printArray(int arr[], int n){
    for(int i =0; i<n;i++)
        cout<<arr[i]<<" ";
}


int main(int argc, char const *argv[])
{
    int arr[] = {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    pushZerosToEnd(arr, n);
    cout<<"Array After Pushing all Element to end: ";
    printArray(arr, n);
    return 0;
}



