#include <iostream>
#include <map>
using namespace std;
/*

Division Method in Hashing for Fetching:->
        modulo number with 10 and then store it inside hash array index
        like 52%10 = 2 store 52 on hash array index 2
        for collision on same index we do chaining at same index(linear chaining)
        and chain is sorted. It's extremely rare case.

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

    // pre-compute
    // in unordered_map storing is O(1) while fecthing is O(N) due to collisions
    map<int, int> mpp; // stores values in sorted order (key are sorted)
    // in normal map anything can be a key like [pair<int,int>] is also key
    // but in unordered_map only individual datatype is key.
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    for (auto it : mpp)
    {
        cout << it.first << " -> " << it.second << endl;
    }

    int q;
    cin >> q;
    while (q--)
    {
        int num;
        cin >> num;

        // fetch
        cout << mpp[num] << " ";
    }

    return 0;
}