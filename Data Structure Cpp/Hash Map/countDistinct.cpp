#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 67, 20, 20, 67, 67, 34, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    int res = 0;
    for(int i=0;i<n;i++){
        bool flag = false;
        for(int j = i-1; j >=0; j--){
            if(arr[j] == arr[i]){
                flag = true;
                break;
            }
        }
        if(flag == false)
            res++;
    }

    cout<<"Distinct Elemet: "<<res;
    return 0;
}

// Time Complexity is O(n^2)
