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

Node *OddEven(Node *head)
{
    vector<int> arr;
    Node *temp = head;

    // temp != NULL && temp->next == NULL cause null->next and null->next->next
    // will give error
    // in odd length LL we can miss last element dur to temp->next == NULL
    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }

    if (temp)
        arr.push_back(temp->data);

    temp = head->next;

    while (temp != NULL && temp->next != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next->next;
    }
    // same in case of even LL can miss last element
    if (temp)
        arr.push_back(temp->data);

    temp = head;
    int i = 0;

    while (temp != NULL)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }

    // T.C. = O(n/2 + n/2 + n)
    // S.C. = O(n)

    return head;
}

/*
To Optimize Space we have to do operations in given LL
*/

Node *OddEven_opt(Node *head)
{
    // O(n/2) * 2(for 2 operations)  &  O(1)
    if (head == NULL || head->next == NULL)
        return head;
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = head->next;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }

    odd->next = evenHead;
    return head;
}

int main()
{
    vector<int> arr = {1, 3, 4, 2, 5, 6};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    // head = OddEven(head);
    // printLL(head);

    head = OddEven_opt(head);
    printLL(head);
    return 0;
}