// Rearrange the array in the alternating positive and negative & vice versa
// Order is not considered in the rearrangment
// Space complexity = O(1) Time Complexity = O(n)

#include<bits/stdc++.h>
using namespace std;

void arrangeArray(int arr[], int n){
    int i = -1;
    for(int j= 0; j<n; j++){
        if(arr[j] < 0){
            i++;
        swap(arr[i], arr[j]);
        }
    }
    int pos = i+1;
    int neg = 0;
    while(pos < n && neg<pos && arr[neg]<0){
        swap(arr[neg+1], arr[pos]);
        neg+=2;
        pos++;
    }
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b= temp;
}

void printArray(int arr[], int n){
    for(int i =0; i<n;i++)
        cout<<arr[i]<<" ";
}

int main(int argc, char const *argv[])
{
    int arr[] = {-5, -2, 5, 2, 4, 7, 1, 8, 0, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"Array Before Rearrangement: ";
    printArray(arr, n);
    arrangeArray(arr, n);
    cout<<endl;
    cout<<"Array After Rearrangement: ";
    printArray(arr, n);
    return 0;
}
