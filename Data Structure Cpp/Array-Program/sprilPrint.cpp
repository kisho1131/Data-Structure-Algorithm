#include<bits/stdc++.h>
using namespace std;

void sprialPrint(int arr[][1000], int m, int n){
    int startRow = 0;
    int endRow  = m-1;
    int startCol = 0;
    int endCol = n-1;
    while(startRow < endRow && startCol < endRow){
        // Print the Left to Right Of the first row;
        for(int i=startCol; i<endCol;i++){
            cout<<arr[startRow][i]<<" ";
        }
        startRow = startRow + 1;
        for(int i= startRow; i<=endRow;i++){
            cout<<arr[i][endCol]<<" ";
        }
        endCol--;
        if(endRow>startRow){
        for(int i = endCol; i>=startCol; i--){
            cout<<arr[endRow][i]<<" ";
        }
        endRow--;
    }
        if(endCol>startCol){
        for(int i=endRow; i<=startRow;i--){
            cout<<arr[i][startCol]<<" ";
        }
        startCol++;
    }
    }
}

int main(int argc, char const *argv[])
{
    int arr[1000][1000];
    int m,n;
    int val = 1;
    cin>>m>>n;
    for(int row=0; row<=m-1;row++){
        for(int col = 0; col<=n-1;col++){
            arr[row][col]=val;
            val++;
            cout<<arr[row][col]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    //cout<<"Sprial Print Of the Array is: ";
    //sprialPrint(arr,m, n);
    return 0;
}
