#include <bits/stdc++.h>
using namespace std;

// comparator which compares elements internally
bool comparator(int first, int second)
{
    return first < second;
}
int main()
{
    // declaring the lists
    list<int> list1 = { 1, 70, 80 };
    list<int> list2 = { 2, 3, 4 };

    // merge operation
    list1.merge(list2, comparator);

    cout << "List: ";

    for (auto it = list1.begin(); it != list1.end(); ++it)
        cout << *it << " ";

    return 0;
} 
