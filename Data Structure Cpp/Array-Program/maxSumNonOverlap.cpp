#include<bits/stdc++.h>
using namespace std;

void findMax(int arr[], int n, int k){
    for(int j =0; j<k; j++){
        int st=0, ed=0,s=0;
        int best=numeric_limits<int>::min();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum<0){
                sum=0;
                s = i+1;
            }
           if(best < sum){
            best = sum;
            st = s;
            ed = i;
           }
        }
        cout << "Maximum non-overlapping sub-array sum"
             << (k+ 1) << ": "<< best
             << ", starting index: " << st
             << ", ending index: " << ed << endl;

        for (int l = st; l <= ed; l++)
            arr[l] = numeric_limits<int>::min();
    }
    cout<<endl;
}

int main(int argc, char const *argv[])
{
    int arr1[] = {4, 1, 1, -1, -3,
                 -5, 6, 2, -6, -2};
    int k1 = 3;
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // Function calling
    findMax(arr1, n1, k1);
    return 0;
}
