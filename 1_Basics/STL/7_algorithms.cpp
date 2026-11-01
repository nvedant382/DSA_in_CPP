#include <algorithm>
#include <iostream>
using namespace std;

// boolean Comparator
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    // sort acc. to 2nd element
    if (p1.second < p2.second)
        return true;
    else if (p1.second > p2.second)
        return false; // returns swap()
    else
    {
        // if both are same
        if (p1.first > p2.first)
            return true;
        else
            return false;
    }
}

int main()
{
    sort(a, a + 4); // 3,1,5,2
    sort(v.begin(), v.end());
    sort(a + 2, a + 4); // if we want only 5,2 to sort

    sort(a, a + 4, greater<int>); // 5,3,2,1

    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};

    sort(a, a + n, comp); // {4,1},{2,1},{1,2}

    int num = 7; // 111
    int cnt = __builtin_popcount();

    long long num = 2345678998;
    int cnt = __builtin_popcountll();

    string s = "123"; // always sort s

    do
    {
        cout << s << " ";
    } while (next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a, a + n);

    return 0;
}