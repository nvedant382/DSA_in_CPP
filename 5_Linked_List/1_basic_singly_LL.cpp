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

void lengthLL(Node *head)
{
    int cnt = 0;
    while (head != nullptr)
    {
        cnt++;
        head = head->next;
    }
    cout << cnt << endl;
}

/* or
void DelteHead(Node* &head){ }
*/
Node *DeleteHead(Node *head)
{
    if (head == NULL)
        return head;

    Node *temp = head;
    head = head->next;
    delete temp; // free()
    return head;
}

Node *DeleteTail(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return nullptr;

    Node *temp = head;

    // 2nd last element
    while (temp->next->next != nullptr)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *DeleteKthNode(Node *head, int k)
{
    if (head == nullptr)
        return nullptr;

    if (k == 1)
    {
        return DeleteHead(head);
    }

    int cnt = 0;
    Node *temp = head, *prev = nullptr;

    while (temp != nullptr)
    {
        cnt++;
        if (cnt == k)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node *DeleteElement(Node *head, int el)
{
    if (head == nullptr)
        return nullptr;

    if (head->data == el)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    Node *prev = nullptr, *temp = head;

    while (temp->next != nullptr)
    {
        if (temp->data == el)
        {
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }

    return head;
}

Node *InsertAtHead(Node *head, int el)
{
    // or 1st constructor itself : Node *newNode = new Node(el,head);
    Node *newNode = new Node(el);
    newNode->next = head;
    head = newNode;
    return head;
}

Node *InsertAtTail(Node *head, int el)
{
    Node *newNode = new Node(el);
    if (head == nullptr)
        return newNode;

    Node *temp = head;

    while (temp->next != nullptr)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Node *InsertAtKthNode(Node *head, int k, int el)
{
    if (head == nullptr)
    {
        if (k == 1)
            return new Node(el);
        else
            return head;
    }

    if (k == 1)
    {
        return InsertAtHead(head, el);
    }

    int cnt = 1;
    Node *temp = head;

    while (temp != nullptr)
    {
        if (cnt == k - 1)
        {
            Node *newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }

        temp = temp->next;
        cnt++;
    }

    return head;
}

Node *InsertBeforeValue(Node *head, int value, int el)
{
    if (head == NULL)
    {
        return head;
    }

    if (head->data == value)
    {
        return new Node(el, head);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == value)
        {
            Node *newNode = new Node(el);
            newNode->next = temp->next;
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }

    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 10};
    Node x = Node(arr[0], nullptr);
    cout << x.data << endl;
    cout << x.next << endl;

    Node *y = &x;
    cout << y->data << endl;
    cout << (*y).next << endl;

    Node *z = new Node(3);
    cout << z->data << endl;

    Node *head = convertLLtoArray(arr);
    cout << head->data << endl;
    printLL(head);
    lengthLL(head);

    head = DeleteHead(head);
    printLL(head);

    head = DeleteTail(head);
    printLL(head);

    head = DeleteKthNode(head, 2);
    printLL(head);

    head = DeleteElement(head, 6);
    printLL(head);

    head = InsertAtHead(head, 10);
    printLL(head);

    head = InsertAtTail(head, 18);
    printLL(head);

    head = InsertAtKthNode(head, 6, 27);
    printLL(head);

    head = InsertBeforeValue(head, 27, 9);
    printLL(head);

    return 0;
}

/* Notes:

🧱 1. Node x = Node(2, NULL);
✅ What this does:
Creates a Node object named x on the stack.

Calls the constructor Node(int data1, Node* next1) with:

data1 = 2

next1 = NULL (end of list)

📦 Where is x stored?
On the stack (i.e., inside the current function’s memory frame).

Automatically destroyed when the function ends.

📌 2. Node* y = &x;
✅ What this does:
Creates a pointer y that stores the address of x.

You are not allocating anything new—just pointing to existing x.

⛔ Be Careful:
If x goes out of scope (e.g., after the function ends), y becomes a dangling pointer (points to garbage).

💥 3. Node* y = new Node(2, NULL);
✅ What this does:
Allocates a new Node on the heap using new.

y now holds the address of that newly allocated Node.

📦 Where is this Node stored?
In the heap — memory that persists until you manually free it with delete.

🧪 Pro Tip: When to use what?
✅ Use Node x = ... for short‑lived or local variables (within one function).

✅ Use new Node(...) when:

You want the object to persist after the function ends.

You need to return it from a function.

You're building dynamic data structures like linked lists.

*/