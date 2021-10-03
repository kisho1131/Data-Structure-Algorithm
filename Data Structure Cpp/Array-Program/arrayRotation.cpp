// Write a function rotate(ar[], d, n) that rotates arr[] of size n by d elements

# include<bits/stdc++.h>
using namespace std;

// Method:1 Using the temporary array

void rotate_arry(int arr[], int n, int d){
    int temp[100];
    int c = 0;
    for(int i = 0; i<d; i++){
        temp[i] = arr[i];
    }
    for(int j=0; j<n-d; j++){
        arr[j] = arr[j+d];
    }
    for(int k = n-d; k<n; k++){
        arr[k] = temp[c];
        c++;
    }
}

// Method:2 Using the Juggling algorithm
int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(a, a % b);
}

void jugglingAlgorithm(int arr[], int n, int d){
    d = d % n; // handling the case when d > n
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        /* move i-th values of blocks */
        int temp = arr[i];
        int j = i;
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
            if (k == i)
                break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,3,4,5,6,7,8,9,10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 5;
    jugglingAlgorithm(arr, n, d);
    for(int i =0; i<n; i++){
        cout<<arr[i] <<" ";
    }
    return 0;
}
