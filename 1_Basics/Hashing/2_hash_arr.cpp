#include <iostream>
using namespace std;
int arr2[10000000]; // allocate only globally
// in main it will give segmentation fault
// in main you can go till 10^6
/*

Cannot allocate big size arrays
cannot hash 10^8,10^12 numbers
therefore we use map, unordered_map in STL in C++

*/
int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // max element is 12 so hash will have 13 (0 to 12 ind)
    int hash[12 + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[arr[i]] += 1;
    }

    int q;
    cin >> q; // queries

    while (q--)
    {
        int number;
        cin >> number;

        cout << hash[number];
    }

    return 0;
}