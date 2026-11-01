#include <iostream>
#include <vector>
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

int lengthLL(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *middle(Node *head)
{
    // Time = O(N + N/2)
    // Space = O(1)
    int n = lengthLL(head);

    int middle = (n / 2) + 1;

    Node *temp = head;
    while (temp != NULL)
    {
        if (--middle == 0)
        {
            return temp;
        }
        temp = temp->next;
    }

    return NULL;
}

Node *middle_opt(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->next;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 10};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    Node *ans = middle(head);
    cout << ans->data << endl;

    ans = middle_opt(head);
    cout << ans->data << endl;
    return 0;
}