#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Queue
{
    Node *start = NULL, *end = NULL;
    int size = 0;

public:
    void push(int x)
    {
        Node *newNode = new Node(x);

        if (start == NULL)
        {
            start = newNode, end = newNode;
        }
        else
        {
            end->next = newNode;
            end = end->next;
        }
        size += 1;
    }

    int pop()
    {
        if (start == NULL)
        {
            cout << "Queue is Full ";
            return -1;
        }

        Node *temp = start;
        int data = temp->data;

        start = start->next;
        delete temp;
        size -= 1;
        return data;
    }

    int top()
    {
        if (start == NULL)
        {
            cout << "Queue is Full ";
            return -1;
        }

        return start->data;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue *q = new Queue();
    cout << q->getSize() << endl;
    cout << q->top() << endl;
    q->push(17);
    q->push(20);
    q->push(8);
    cout << q->top() << endl;
    cout << q->pop() << endl;
    cout << q->top() << endl;
    cout << q->getSize() << endl;

    return 0;
}