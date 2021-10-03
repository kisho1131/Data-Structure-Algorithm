// Given an array of integers, segregate even and odd numbers in the array.
// All the even numbers should be present first, and then the odd numbers.
// Time complexity:- O(n)
// Space Complexity :- O(1)

#include<bits/stdc++.h>
using namespace std;

int arrayEvenAndOdd(int arr[], int n){
    int i =-1;
    int j =0;
    while(j!=n){
        if(arr[j] %2 ==0){
            i++;
            swap(arr[i], arr[j]);
        }
        j++;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n;i++)
        cout<<arr[i] <<" ";
}

int main()
{
    int arr[] = { 1, 3, 2, 4, 7, 6 };
    int n = sizeof(arr) / sizeof(int);
    arrayEvenAndOdd(arr, n);
    cout<<"Array After rearrangemnt is:";
    cout<<endl;
    printArray(arr, n);
    return 0;
}
