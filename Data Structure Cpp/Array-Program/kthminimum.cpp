#include <bits/stdc++.h>
using namespace std;

int main() {
    int test;
    int n;
    int d;
    cin>>test;
    for(int k=0;k<test; k++){
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>d;
    sort(arr, arr+n);
    int pos = 0;
    for(int j =0; j<d; j++){
        pos++;
    }
    cout<<arr[pos]<<endl;

}
    return 0;
}
