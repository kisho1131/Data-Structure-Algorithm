#include<bits/stdc++.h>
using namespace std;

void segrateZero(int arr[], int n){
    int left = 0;
    int right = n-1;
    while(left<right){
        if(arr[left]==0 && left<right)
            left++;
        if(arr[right]==1 && left<right)
            right--;

        if(left < right){
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 1, 1, 1,0,0,1,0,1,0};
    int i, arr_size = sizeof(arr)/sizeof(arr[0]);
    segrateZero(arr, arr_size);
    cout << "Array after segregation ";
    cout<<endl;
    for (i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
    return 0;
}
