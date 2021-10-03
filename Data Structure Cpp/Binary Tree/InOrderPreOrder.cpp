#include<iostream>
using namespace std;

int search(int arr[], int key, int n){
    int index = -1;
    for(int i=0; i<n; i++){
        if(arr[i] == key)
            index = i;
    }
    return index;
}
void PrintPostorder(int in[], int pre[], int n){
    //int root = pre[0];
    int index = search(in, pre[0], n);

    // Check for the Left Subtree
    if(index!=0){
        PrintPostorder(in, pre+1, index);
    }

    // Check for the Right SubTree
    if(index!=n-1){
        PrintPostorder(in+index+1, pre+index+1, n-index-1);
    }
    cout<<pre[0]<<" ";
}

int main(int argc, char const *argv[])
{

    int in[] = { 4, 2, 5, 1, 3, 6 };
    int pre[] = { 1, 2, 4, 5, 3, 6 };
    int n = sizeof(in) / sizeof(in[0]);
    cout << "Postorder traversal " << endl;
    PrintPostorder(in, pre, n);
    return 0;
}
