#include <set>
#include <unordered_set>
#include <iostream>
using namespace std;

// Sets store unique values and are sorted
// internally uses Tree
// begin,end,rend,rbegin,size,empty,swap,erase are same as vector
// uses tree inernally, so push() and pop() takes O(log N)

void multiSet()
{
    // Stores duplicates
    multiset<int> ms;
    ms.insert(1);
    ms.insert(1);
    ms.insert(1); // {1,1,1}

    ms.erase(1); // removes all 1's

    int cnt = ms.count(1); // 3

    ms.erase(ms.find(1));                 // removes 1st occurence
    ms.erase(ms.find(1), ms.find(1) + 2); // removes 2 occurences
}

void unorderedSet()
{
    unordered_set<int> us;
    // every thins is same as ordered(normal) set
    // but diff is, it doesn't store elements in order
    // no sorted order,randomised order everytime

    // Most Operation in O(1), in worst case due to collision it may be O(N)
}

int main()
{
    set<int> s;
    s.insert(1);
    s.emplace(2);
    s.insert(3);
    s.insert(4);
    s.emplace(5);

    auto it = s.find(3);

    auto it = s.find(6); // returns s.end() pointer

    s.erase(5);

    auto it1 = s.find(1); // log n
    auto it2 = s.find(3);
    st.erase(it1, it2); // log N

    auto it3 = st.lower_bound(2);
    auto it4 = st.upper_bound(3); // log n

    cout << *(it3) << " " << *(it4) << endl;

    return 0;
}