// Given an array of numbers, arrange them in a way that yields the largest value
// And if the given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement
// 998764543431 gives the largest value

#include<bits/stdc++.h>
using namespace std;

int compare(string X, string Y){
    string XY = X.append(Y);
    string YX = Y.append(X);
    // Compare the both string:
    return XY.compare(YX)>0?1:0;
}
void findBiggest(vector<string> arr){
    sort(arr.begin(), arr.end(), compare);
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i];
    }
}

int main(int argc, char const *argv[])
{
    vector<string> arr;
    //output should be 6054854654
    arr.push_back("54");
    arr.push_back("546");
    arr.push_back("548");
    arr.push_back("60");
    findBiggest(arr);
    return 0;
}
