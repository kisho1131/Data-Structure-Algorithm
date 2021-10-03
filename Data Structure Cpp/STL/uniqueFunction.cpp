#include <bits/stdc++.h>
using namespace std;

// Function for binary_predicate
bool compare(double a, double b)
{
    return ((int)a == (int)b);
}

// Driver code
int main()
{
    list<double> list = { 2.55, 3.15, 4.16, 4.16,
                          4.77, 12.65, 12.65, 13.59,4.16, 4.15 };

    cout << "List is Before unique: ";
    for (auto it = list.begin(); it != list.end(); ++it)
        cout << *it << " ";
    cout<<endl;
    // unique operation on list with no parameters
    list.unique();

    // starts from the first element
    // of the list to the last
    cout<<"List After Unique: ";
    for (auto it = list.begin(); it != list.end(); ++it)
        cout << *it << " ";

    // unique operation on list with parameter
    // list.unique(compare); ----> take the compare Function as the parameter and compare accordingly.

    // cout << "\nList is: ";

    // starts from the first element
    // of the list to the last
    // for (auto it = list.begin(); it != list.end(); ++it)
        // cout << *it << " ";

    return 0;
}
