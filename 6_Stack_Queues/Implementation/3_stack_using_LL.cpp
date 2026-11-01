#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Stack
{
    int size = 0;
    Node *top = NULL;

public:
    // all operations O(1)
    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }

        Node *temp = top;
        top = top->next;
        int data = temp->data;
        delete temp;
        size -= 1;
        return data;
    }

    int peek()
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return -1;
        }
        return top->data;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Stack *st = new Stack();
    cout << st->getSize() << endl;
    st->push(10);
    st->push(7);
    st->push(23);
    st->push(8);

    cout << st->peek() << endl;
    cout << st->getSize() << endl;

    cout << st->pop() << endl;
    cout << st->peek() << endl;
    cout << st->getSize() << endl;
    return 0;
}