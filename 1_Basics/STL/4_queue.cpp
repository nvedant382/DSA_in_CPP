#include <iostream>
#include <queue>
using namespace std;

// internally works as Tree (push & pop -> O(log N))
void explainPQ()
{
    // Maximum Heap
    priority_queue<int> pq;
    pq.push(2);
    pq.push(8);
    pq.push(3);
    pq.emplace(10);

    cout << pq.top();
    pq.pop();
    cout << pq.top();

    // Minimum Heap
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq.push(2);
    pq.push(8);
    pq.push(3);
    pq.emplace(10);

    cout << pq2.top();
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.emplace(3);

    q.back() += 5;

    cout << q.back();

    cout << q.front();

    q.pop();

    cout << q.front();

    return 0;
}