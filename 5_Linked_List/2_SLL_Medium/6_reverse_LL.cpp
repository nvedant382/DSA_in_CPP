#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *next;

    // this pointer is passed as first argument internally
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertLLtoArray(vector<int> &arr)
{
    Node *head = new Node(arr[0], nullptr);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr);
        mover->next = temp;
        mover = mover->next; // or mover = temp;
    }

    return head;
}

void printLL(Node *head)
{
    // changes in head will not reflect globally
    while (head != nullptr)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "x" << endl;
}

Node *reverseLL(Node *head)
{
    // T.C. = O(2n)  &  S.C. = O(n)
    stack<int> st;

    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node *reverseLL_opt(Node *head)
{
    // O(n)  &  O(1)
    if (head == NULL || head->next == NULL)
        return head;

    Node *last = NULL, *current = head, *front;

    while (current != NULL)
    {
        front = current->next;
        current->next = last;
        last = current;
        current = front;
    }

    return last;
}

// Time = O(N) N recursive call
// Space = O(N) recursive stack space
Node *reverseLL_recursive(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *newHead = reverseLL_recursive(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 10};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    head = reverseLL(head);
    printLL(head);

    head = reverseLL_opt(head);
    printLL(head);

    head = reverseLL_recursive(head);
    printLL(head);

    return 0;
}