#include <map>
#include <iostream>
using namespace std;

// Key-value pair key must be unique
// map stores keys in sorted order

// multimap -> can store same keys(multiple) 

// unordered-map -> works in O(1) is most of time,while normal map in O(log n)
int main()
{
    map<int, int> mpp;
    map<int, pair<int, int>> mpp2;
    map<pair<int, int>, int> mpp3;

    mpp[1] = 2;
    mpp.insert({3, 1});
    mpp.emplace({2, 4});

    mpp[{2, 3}] = 10;

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    cout << mpp[1];
    cout << mpp[5]; // if key with value5 not exist, mpp prints 0

    auto it = mpp.find(5);
    auto it2 = mpp.find(7); // not exist, return .end()

    // erase,size,empty,swap,lower_bound(),upper_bound() are same as above

    return 0;
}