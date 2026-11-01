#include <iostream>
#include <vector>
#include <map>
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

Node *detectLoop(Node *head)
{
    // Time = O(N * 2 * logN) -> 2 map operations
    // Space = O(N)
    map<Node *, int> mpp;

    Node *temp = head;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {

            return temp;
        }

        mpp[temp]++;
        temp = temp->next;
    }

    return nullptr;
}

bool detectLoop_opt(Node *head)
{
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        // in loop, fast == slow are meant to meet at one point because
        // fast is moving by 2 steps , slow by 1 step so net distance is -1
        // always at one point due -1,-1,... distance will become 0.
        // d%1 == 0
        // Space is constant and Time = O(N)
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            return true;
    }

    return false;
}

int length_of_Loop(Node *head)
{
    // Time = O(N * 2 * logN) -> 2 map operations
    // Space = O(N)
    Node *temp = head;
    int timer = 1;
    map<Node *, int> mpp;

    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return (timer - mpp[temp]);
        }
        mpp[temp] = timer;
        timer++;
        temp = temp->next;
    }

    return 0;
}

int findLength(Node *slow, Node *fast)
{
    int len = 1;
    fast = fast->next;
    while (slow != fast)
    {
        len++;
        fast = fast->next;
    }
    return len;
}

int length_of_Loop_opt(Node *head)
{
    // Time = O(n + k) which is O(n) since k ≤ n
    Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;

        if (slow == fast)
            return findLength(slow, fast);
    }

    return 0;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = head->next->next;

    cout << (*detectLoop(head)).data << endl;
    cout << detectLoop_opt(head) << endl;
    cout << length_of_Loop(head) << endl;
    cout << length_of_Loop_opt(head) << endl;

    return 0;
}