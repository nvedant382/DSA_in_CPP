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
    while (head != NULL)
    {
        head = head->next;
        cnt++;
    }
    return cnt;
}

Node *Delete_Nth_Last(Node *head, int n)
{
    // Time = O(len) + O(len-n) = O(2n) if n=1  and  Space = O(1)
    int len = lengthLL(head);

    if (len == n)
    {
        Node *newHead = head->next;
        delete head;
        return newHead;
    }

    int node = len - n;
    Node *temp = head;

    while (temp != NULL)
    {
        if (node == 1)
            break;
        node--;
        temp = temp->next;
    }

    Node *delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

Node *Delete_Nth_Last_opt(Node *head, int n)
{
    Node *fast = head;
    for (int i = 1; i <= n; i++)
        fast = fast->next;

    if (fast == NULL)
    {
        Node *newhead = head->next;
        delete head;
        return newhead;
    }

    Node *slow = head;
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 10};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    head = Delete_Nth_Last(head, 4);
    printLL(head);

    head = Delete_Nth_Last(head, 4);
    printLL(head);
    return 0;
}