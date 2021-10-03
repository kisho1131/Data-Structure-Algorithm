#include<bits/stdc++.h>
using namespace std;

void merge(int arr1[], int m, int arr2[], int n){
    int size;
    if(m>n)
        size = m*m;
    else
        size = n*n;
    int *arr = new int[size];
    int s = n+m;
    int pos = 0;
    for(int i=0;i<m; i++){
        arr[i] = arr1[i];
        pos = i;
        }
    for(int k = pos+1,j =0;k<n+pos; k++){
        arr[k] = arr2[j];
        j++;
    }
    sort(arr, arr+s);
    for(int j=0;j<s;j++)
        cout<<arr[j]<<" ";
}
int main(int argc, char const *argv[])
{
    int arr1[] = {1,2,3};
    int arr2[] = {3,2,5};
    merge(arr1, 3, arr2, 3);
    return 0;
}
