#include <iostream>
#include <stack>
using namespace std;

string preFix_to_infix(string s)
{
    stack<string> st;
    int n = s.length(), i = n - 1;

    while (i >= 0)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            st.push(string(1, s[i]));
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();

            string str = "(" + op2 + s[i] + op1 + ")";
            st.push(str);
        }
        i--;
    }
    return st.top();
}

int main()
{
    cout << preFix_to_infix("*+PQ-MN") << endl;
    return 0;
}