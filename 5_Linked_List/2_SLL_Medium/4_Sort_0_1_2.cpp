#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

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

Node *sortLL(Node *head)
{
    // O(2n)  and  O(1)
    if (head == NULL || head->next == NULL)
        return head;

    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
            cnt0++;
        else if (temp->data == 1)
            cnt1++;
        else
            cnt2++;

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (cnt0)
        {
            temp->data = 0;
            cnt0--;
        }
        else if (cnt1)
        {
            temp->data = 1;
            cnt1--;
        }
        else
        {
            temp->data = 2;
            cnt2--;
        }
        temp = temp->next;
    }

    return head;
}

Node *sortLL_opt(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    // segrregate 0 1 2 nodes and oin them to sort in 1 pass
    // Tie = O(N)   and   Space = O(1)
    Node *ZeroHead = new Node(-1);
    Node *OneHead = new Node(-1);
    Node *TwoHead = new Node(-1);

    Node *zero = ZeroHead, *one = OneHead, *two = TwoHead, *temp = head;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }

    zero->next = OneHead->next ? OneHead->next : TwoHead->next;
    one->next = TwoHead->next;
    two->next = NULL;

    Node *newHead = ZeroHead->next;

    delete ZeroHead, OneHead, TwoHead;

    return newHead;
}

int main()
{
    vector<int> arr = {1, 0, 1, 2, 0, 2, 1};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    head = sortLL_opt(head);
    printLL(head);

    return 0;
}