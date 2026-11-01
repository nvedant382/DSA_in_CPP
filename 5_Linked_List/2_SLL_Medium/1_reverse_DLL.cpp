#include <iostream>
#include <vector>
#include <stack>
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

Node *convertLLtoArray(vector<int> &arr)
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

Node *reverseLL(Node *head)
{
    // T.C. = O(2n)  &  S.C. = O(n)
    stack<int> st;

    Node *temp = head;
    while (temp != NULL)
    {
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while (temp != NULL)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    return head;
}

Node *reverseLL_opt(Node *head)
{
    // O(N)  &  O(1)  using concept of third var like swap(a,b)
    if (head == NULL || head->next == NULL)
        return head;

    Node *last = NULL, *current = head;

    while (current != NULL)
    {
        last = current->back;
        current->back = current->next;
        current->next = last;
        current = current->back;
    }

    return last->back;
}

/*
for SLL :

Node* last = null,*front = null,*current = head

while(current!=null){
    front = current->next;
    current->next = prev;
    prev = current;
    current = front;
}

return last;

*/

int main()
{
    vector<int> arr = {1, 2, 3, 4, 6, 7, 10};
    Node *head = convertLLtoArray(arr);
    printLL(head);

    head = reverseLL(head);
    printLL(head);

    head = reverseLL_opt(head);
    printLL(head);
    return 0;
}