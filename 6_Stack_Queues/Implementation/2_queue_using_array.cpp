#include <iostream>
using namespace std;

class Queue
{
    int size;
    int *q;
    int currSize;
    int start;
    int end;

public:
    Queue(int size)
    {
        this->size = size;
        q = new int[size];
        currSize = 0;
        start = -1;
        end = -1;
    }

    void push(int x)
    {
        if (currSize == size)
        {
            cout << "Queue is full" << endl;
            return;
        }

        if (currSize == 0)
        {
            start = 0, end = 0;
        }
        else
        {
            end = (end + 1) % size;
        }

        q[end] = x;
        currSize++;
    }

    int pop()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty: ";
            return -1;
        }

        int data = q[start];

        if (start == end)
        {
            start = -1;
            end = -1;
            currSize = 0;
        }
        else
        {
            start = (start + 1) % size;
            currSize -= 1;
        }

        return data;
    }

    int top()
    {
        if (currSize == 0)
        {
            cout << "Queue is empty: ";
            return -1;
        }

        return q[start];
    }
};

int main()
{
    Queue *q = new Queue(10);
    cout << q->top() << endl;
    q->push(6);
    q->push(7);
    q->push(8);
    cout << q->pop() << endl;
    return 0;
}