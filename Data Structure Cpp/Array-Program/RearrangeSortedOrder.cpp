// Given a sorted array of positive integers, rearrange the array alternately
// i.e first element should be the maximum value,
// second minimum value, third-second max, fourth-second min and so on.

#include<bits/stdc++.h>
using namespace std;

void RearrangeArray(int arr[], int n){
    int max_idx = n-1;
    int min_idx = 0;
    int max_ele = arr[max_idx] + 1;
    for(int i =0; i<n; i++){
        // We put the maximum element in the even index
        if(i%2 ==0){
            arr[i] += (arr[max_idx] % max_ele) *max_ele;
            max_idx--;
        }
        // We place the Minimum element at the odd index
        else{
            arr[i] += (arr[min_idx] % max_ele)*max_ele;
            min_idx++;
        }
    }
    for(int i= 0; i<n; i++){
            arr[i] = arr[i] / max_ele;
        }
}

int main(int argc, char const *argv[])
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    RearrangeArray(arr, n);

    cout << "\nModified Array\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
