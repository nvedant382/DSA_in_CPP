#include <stack>
#include <iostream>
using namespace std;

// LIFO
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.emplace(3);
    st.emplace(4);

    cout << st.top() << endl;

    st.pop();

    cout << st.top() << endl;

    cout << st.size() << endl;

    cout << st.empty() << endl;

    stack<int> st1, st2;
    st1.swap(st2);

    return 0;
}