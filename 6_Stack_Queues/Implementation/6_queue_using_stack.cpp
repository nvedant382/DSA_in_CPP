#include <iostream>
#include <stack>
using namespace std;

class Queue
{
    stack<int> s1, s2;

public:
    // O(2n)
    void push(int x)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int data = s1.top();
        s1.pop();
        return data;
    }

    int top()
    {
        return s1.top();
    }

    bool isEmpty()
    {
        return (s1.size() == 0);
    }
};

class Queue2
{
    stack<int> s1, s2;

public:
    // O(1)
    void push(int x)
    {
        s1.push(x);
    }

    // O(N)
    int pop()
    {
        if (!s2.empty())
        {
            int data = s2.top();
            s2.pop();
            return data;
        }
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }

            int data = s2.top();
            s2.pop();
            return data;
        }
    }

    // O(N)
    int top()
    {
        if (!s2.empty())
        {
            return s2.top();
        }
        else
        {
            while (s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }

            return s2.top();
        }
    }
};

int main()
{
    Queue *q = new Queue();
    cout << q->isEmpty() << endl;

    q->push(2);
    q->push(3);
    q->push(5);

    cout << q->top() << endl;
    cout << q->pop() << endl;

    cout << q->top() << endl;

    cout << "Queue 2: " << endl;
    Queue2 *q2 = new Queue2();

    q2->push(2);
    q2->push(3);
    q2->push(5);

    cout << q2->top() << endl;
    cout << q2->pop() << endl;

    cout << q2->top() << endl;

    return 0;
}