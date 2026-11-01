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

bool checkPalindrome(Node *head)
{
    // Time = O(2n)   and   Space = O(n)
    stack<int> st; // LIFO structure

    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        if (temp->data != st.top())
            return false;
        st.pop();
        temp = temp->next;
    }

    return true;
}

Node *reverse(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *newHead = reverse(head->next);
    Node *front = head->next;
    front->next = head;
    head->next = NULL;

    return newHead;
}

// Time = O(n/2) + O(n/2) + O(n/2) + O(n/2) = O(2n)
// Space O(1) or O(n)
/*
 you only rearrange the existing pointers
 (aside from the recursion stack in your reverse,
 which is O(n) in the worst case).
*/
bool checkPalindrome_opt(Node *head)
{
    // 3 Steps = Finding Middle + Reversing Middle+1 part + Comparing

    if (head == nullptr || head->next == nullptr)
    {
        return true;
    }

    // Step 1 : Tortoise and Hare Method
    Node *slow = head, *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }

    // Step 2
    Node *newHead = reverse(slow->next);
    Node *first = head, *second = newHead;

    // step 3
    while (NULL != second)
    {
        if (first->data != second->data)
        {
            reverse(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverse(newHead);
    return true;
}

int main()
{
    vector<int> arr = {1, 2, 3, 2, 1};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    cout << checkPalindrome(head) << endl;
    cout << checkPalindrome_opt(head) << endl;

    return 0;
}