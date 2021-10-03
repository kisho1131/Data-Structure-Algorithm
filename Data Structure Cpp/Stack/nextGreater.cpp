#include<bits/stdc++.h>
using namespace std;

void printNextGreater(int arr[], int n) {
    stack <int> s;
    s.push(arr[0]);
    for (int i = 1; i < n; i++) {
        if (s.empty())
            s.push(arr[i]);
        while (!s.empty() && s.top() < arr[i]) {
            cout << s.top() << " -->" << arr[i] << endl;
            s.pop();
        }
        s.push(arr[i]);
    }
    while (!s.empty()) {
        cout << s.top() << " -->" << -1 << endl;
        s.pop();
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {11, 13, 21, 3, 4, 22, 45, 7, 69};
    int n = sizeof(arr) / sizeof(arr[0]);
    printNextGreater(arr, n);
    return 0;
}
