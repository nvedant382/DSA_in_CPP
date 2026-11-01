#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q;

public:
    // O(n)
    void push(int x)
    {
        int size = q.size();
        q.push(x);

        for (int i = 1; i <= size; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    int pop()
    {
        if (q.size() == 0)
            return -1;

        int data = q.front();
        q.pop();
        return data;
    }

    int top()
    {
        if (q.size() == 0)
            return -1;

        return q.front();
    }

    bool isEmpty()
    {
        return (q.size() == 0);
    }
};

int main()
{
    Stack *s = new Stack();
    s->push(4);
    s->push(9);
    s->push(2);

    cout << s->isEmpty() << endl;
    cout << s->top() << endl;

    cout << s->pop() << endl;
    cout << s->top() << endl;

    return 0;
}