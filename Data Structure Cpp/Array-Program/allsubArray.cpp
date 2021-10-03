#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int arr[] = {5,1,4,7,8,3,9,2,11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxelement = 0;
    int currentsum = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n; j++){
            currentsum = 0;
            for(int k = i; k<=j;k++){
                currentsum += arr[k];
                }
                if(currentsum > maxelement){
                    maxelement = currentsum;
                }
            }
        }
    cout<<"Maximum Element : "<<maxelement;
    return 0;
}
