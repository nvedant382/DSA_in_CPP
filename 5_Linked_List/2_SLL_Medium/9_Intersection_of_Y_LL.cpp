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

int find_intersection(Node *head1, Node *head2)
{
    // Time = O(N1*logN1) + O(N2*logN2)
    // Space = O(N1) or O(N2) depends which lL is storing
    map<Node *, int> mpp;
    Node *temp = head1;
    while (temp != NULL)
    {
        mpp[temp] = 1;
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp->data;
        }
        temp = temp->next;
    }

    return 0;
}

int lengthLL(Node *head)
{
    int cnt = 0;
    while (head != NULL)
    {
        cnt++;
        head = head->next;
    }
    return cnt;
}

Node *collisionPoint(Node *smaller, Node *larger, int d)
{
    while (d--)
    {
        larger = larger->next;
    }

    while (larger != NULL)
    {

        if (larger == smaller)
            return larger;

        larger = larger->next;
        smaller = smaller->next;
    }

    return NULL;
}

Node *getIntersectionNode(Node *head1, Node *head2)
{
    // Time = O(N1) + O(N2) + O(N2-N1) + O(N1) = O(N1 + 2N2)
    // Space = O(1)
    int len1 = lengthLL(head1);
    int len2 = lengthLL(head2);

    int d = len2 > len1 ? len2 - len1 : len1 - len2;

    if (len1 < len2)
    {
        return collisionPoint(head1, head2, len2 - len1);
    }
    else
    {
        return collisionPoint(head2, head1, len1 - len2);
    }

    return NULL;
}

Node *getIntersectionNode_opt(Node *head1, Node *head2)
{
    /* using this algorithm it is confirm that both t1 and t2 will meet at one
    point if they not, they both will be NULL for sure
    as it is made sure that even of LL is not equal lengths still
    it sure that both pointers will have same (distance)
    and when swapping that position opposite LL heads,
    distance will become 0 eventually
    */

    // T.C. = O(N1 + N2)  and  S.C. = O(1)
    Node *t1 = head1, t2 = head2;

    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
            return t1;

        if (t1 == NULL)
            t1 = head2;
        if (t2 == NULL)
            t2 = head1;
    }

    return t1; // or t2 as both are NULL if there is no collision
}

int main()
{
    vector<int> arr = {2, 1, 4, 6, 2};
    vector<int> arr2 = {1, 2, 4, 5};
    Node *head = convertLLtoArray(arr);
    printLL(head);
    Node *head2 = convertLLtoArray(arr2);
    printLL(head2);

    Node *temp = head;

    while (temp->data != 4)
    {
        temp = temp->next;
    }

    Node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }

    temp2->next = temp;
    printLL(head2);

    cout << find_intersection(head, head2) << endl;

    return 0;
}