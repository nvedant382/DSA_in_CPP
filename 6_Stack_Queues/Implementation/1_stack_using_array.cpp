#include <iostream>
using namespace std;

class Stack
{
    int capacity;
    int top;
    // int st[size];
    int *st;

public:
    Stack(int size)
    {
        capacity = size;
        st = new int[size];
        top = -1;
    }

    ~Stack()
    {
        delete[] st;
    }

    void push(int x)
    {
        if (top + 1 >= 10)
        {
            cout << "Stack is full" << endl;
            return;
        }

        // top++;
        st[++top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        // int data = st[top];
        // top--;
        // return data;
        return st[top--];
    }

    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return st[top];
    }

    int getSize()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        return top + 1;
    }

    bool isEmpty()
    {
        return top == -1;
    }
};

int main()
{
    Stack *st = new Stack(10);
    cout << st->isEmpty() << endl;
    cout << st->getSize() << endl;
    cout << st->peek() << endl;

    st->push(5);
    st->push(7);
    st->push(10);

    cout << st->peek() << endl;
    cout << st->getSize() << endl;
    cout << st->pop() << endl;
    cout << st->getSize() << endl;
    return 0;
}