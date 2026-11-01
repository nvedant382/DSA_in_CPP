#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

    Node(int data, Node *next, Node *back)
    {
        this->data = data;
        this->next = next;
        this->back = back;
    }

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

Node *convert2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *back = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], NULL, back);
        back->next = temp;
        back = temp;
    }

    return head;
}

void printLLForward(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "x" << endl;
}

void printLLBackward(Node *head)
{
    if (head == NULL)
        return;

    while (head->next != NULL)
    {
        head = head->next;
    }

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->back;
    }
    cout << "x" << endl;
}

Node *DeleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;

    Node *back = head;
    head = head->next;

    back->next = NULL;
    head->back = NULL;
    delete back;

    return head;
}

Node *DeleteTail(Node *head)
{
    if (head == NULL && head->next == NULL)
    {
        return NULL;
    }

    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }

    tail->back->next = NULL;
    tail->back = NULL;
    delete tail;

    return head;
}

Node *DeleteKthNode(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    int cnt = 0;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }
    Node *front = temp->next;
    Node *prev = temp->back;

    if (front == NULL && prev == NULL)
    {
        delete temp;
        return NULL;
    }

    if (front == NULL)
    {
        return DeleteTail(head);
    }

    if (prev == NULL)
    {
        return DeleteHead(head);
    }

    front->back = prev;
    prev->next = front;
    temp->back = NULL;
    temp->next = NULL;
    delete temp;
    return head;
}

Node *DeleteElement(Node *head, int el)
{
    if (head == NULL)
    {
        return head;
    }

    int cnt = 0;
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == el)
        {
            break;
        }
        temp = temp->next;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL && prev == NULL)
    {
        delete temp;
        return NULL;
    }
    else if (front == NULL)
    {
        return DeleteTail(head);
    }
    else if (prev == NULL)
    {
        return DeleteHead(head);
    }

    prev->next = front;
    front->back = prev;

    temp->back = NULL;
    temp->next = NULL;
    delete temp;

    return head;
}

Node *InsertAtHead(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }

    Node *newNode = new Node(data);
    newNode->next = head;
    head->back = newNode;
    head = newNode;
    return head;
}

Node *InsertAtEnd(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(data);
    newNode->back = temp;
    temp->next = newNode;
    return head;
}

Node *InsertBeforeEnd(Node *head, int data)
{
    if (head == NULL)
    {
        return new Node(data);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *lastSecond = temp->back;
    Node *newNode = new Node(data, temp, lastSecond);
    lastSecond->next = newNode;
    temp->back = newNode;

    return head;
}

Node *InsertAtKthNode(Node *head, int data, int k)
{
    if (head == NULL)
        return NULL;

    int cnt = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }

    if (temp == NULL && k == cnt + 1)
    {
        return InsertAtEnd(head, data);
    }
    else if (temp == NULL)
    {
        return head;
    }

    Node *prev = temp->back;
    Node *front = temp->next;

    if (front == NULL && prev == NULL)
    {
        delete temp;
        return NULL;
    }
    else if (front == NULL)
    {
        return InsertBeforeEnd(head, data);
    }
    else if (prev == NULL)
    {
        return InsertAtHead(head, data);
    }

    Node *newNode = new Node(data, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

int main()
{
    vector<int> arr = {2, 3, 1, 8, 5};

    Node *head = convert2LL(arr);
    printLLForward(head);
    printLLBackward(head);

    head = DeleteHead(head);
    printLLForward(head);

    head = DeleteTail(head);
    printLLForward(head);

    head = DeleteKthNode(head, 2);
    printLLForward(head);

    head = InsertAtHead(head, 10);
    printLLForward(head);

    head = DeleteElement(head, 8);
    printLLForward(head);

    head = InsertAtEnd(head, 18);
    printLLForward(head);

    head = InsertAtKthNode(head, 45, 4);
    printLLForward(head);

    return 0;
}