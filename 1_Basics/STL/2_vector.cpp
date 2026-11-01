#include <iostream>
#include <vector>
#include <deque>
using namespace std;

// list is also a container with same methods
// but has push_front() and emplace_front()

void dequeDemo()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_front(2);

    dq.emplace_front(4);
    dq.emplace_back(5);

    dq.pop_back();
    dq.pop_front();

    dq.front();
    dq.end();
}

int main()
{
    vector<int> v; // {}

    v.push_back(1);    // Constructs d first, then copies it
    v.emplace_back(2); // Constructs directly in the vector

    vector<pair<int, int>> vec;

    vec.push_back({1, 2});
    vec.emplace_back(1, 2); // assumes as pair

    vector<int> v2(5, 100); // 5 instances of 100

    vector<int> v3(v2); // creates new copy vs from v2

    // **** Iterating ****

    /*

    (*) Why ::?
    - Because C++ allows different containers to have different iterator types.
    - The iterator type depends on the container, so you need to specify which
    container’s iterator you’re using.

    */

    vector<int> v4 = {20, 15, 6, 18, 25, 7, 45};
    vector<int>::iterator it = v4.begin();
    // v.begin() points to memory so it stores a memory (referencing)
    it++;
    cout << *(it) << endl;

    it = it + 2;
    cout << *(it) << endl;

    vector<int>::iterator it2 = v4.end();

    it2--; // points to memory after last element
    cout << *(it2) << endl;

    cout << v4[0] << " " << v4.at(0) << endl;

    cout << v4.back() << endl; // last element of vector

    for (vector<int>::iterator it = v4.begin(); it != v4.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    for (auto it = v4.begin(); it != v4.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    for (auto it2 : v4)
    {
        cout << (it2) << " ";
    }

    cout << endl;

    v4.erase(v4.begin() + 1);

    v4.erase(v4.begin() + 2, v4.begin() + 5);

    for (auto it2 : v4)
    {
        cout << (it2) << " ";
    }

    vector<int> v5(2, 100);           // {100,100}
    v5.insert(v5.begin(), 200);       // {200,100,100}
    v5.insert(v5.begin() + 1, 2, 10); // {200,10,10,100,100}

    vector<int> copy(2, 50);                         //{50,50}
    v5.insert(v5.begin(), copy.begin(), copy.end()); // {50,50,200,10,10,100,100}

    cout << v5.size() << endl;

    v5.pop_back();

    // v -> {1,2}
    // v2 -> {3,4}
    v.swap(v2); // Now, v->{3,4} and v2->{1,2}

    v5.clear(); // erases all elements from vector

    cout << v5.empty();

    return 0;
}