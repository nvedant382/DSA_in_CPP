#include <iostream>
#include <vector>
#include <stack>
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

Node *Add2Numbers(Node *head1, Node *head2)
{
    // O(max(T1,T2))   &   O(max(T1,T2))
    Node *DummyNode = new Node(-1);
    int carry = 0;
    Node *t1 = head1, *t2 = head2, *current = DummyNode;

    while (t1 != NULL || t2 != NULL)
    {
        int sum = carry;
        if (t1)
            sum += t1->data;
        if (t2)
            sum += t2->data;

        Node *newNode = new Node(sum % 10);
        carry = sum / 10;
        current->next = newNode;

        if (t1)
            t1 = t1->next;
        if (t2)
            t2 = t2->next;
        current = current->next;
    }

    if (carry)
    {
        current->next = new Node(1);
    }

    return DummyNode->next;
}

int main()
{
    vector<int> arr = {2, 4, 3};
    vector<int> arr2 = {5, 6, 4};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    Node *head2 = convertLLtoArray(arr2);
    printLL(head2);

    Node *ans = Add2Numbers(head, head2);
    printLL(ans);
    return 0;
}