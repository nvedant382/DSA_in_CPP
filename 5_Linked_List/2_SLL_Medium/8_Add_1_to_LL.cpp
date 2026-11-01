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

Node *reverse(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

Node *add_1_to_LL(Node *head)
{
    // Time = O(3N) = reverse + traverse + reverse
    // Space = O(1)

    head = reverse(head);
    Node *temp = head;
    int carry = 1;

    while (temp != NULL)
    {
        temp->data = temp->data + carry;

        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        else
        {
            temp->data = 0;
            carry = 1;
        }
        temp = temp->next;
    }

    if (carry)
    {
        Node *newNode = new Node(1);
        head = reverse(head);
        newNode->next = head;
        return newNode;
    }

    head = reverse(head);
    return head;
}

int helper(Node *head)
{
    if (head == NULL)
        return 1;

    carry = helper(temp->next);
    temp->data = temp->data + carry;
    if (temp->data < 10)
    {
        return 0;
    }
    else
    {
        temp->data = 0;
        return 1;
    }
}

Node *add_1_to_LL_opt(Node *head)
{
    // O(N)   and    O(N)
    Node *temp = head;
    int carry = helper(temp);

    if (carry)
    {
        Node *newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }

    return head;
}

int main()
{
    vector<int> arr = {9, 9, 9, 9};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    head = add_1_to_LL(head);
    printLL(head);

    return 0;
}