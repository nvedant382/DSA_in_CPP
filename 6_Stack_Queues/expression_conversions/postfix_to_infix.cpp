#include <iostream>
#include <stack>
using namespace std;

string postFix_to_infix(string s)
{
    stack<string> st;
    int n = s.length(), i = 0;

    while (i < n)
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

            string str = "(" + op1 + s[i] + op2 + ")";
            st.push(str);
        }
        i++;
    }
    return st.top();
}

int main()
{
    cout << postFix_to_infix("AB-DE+F*/") << endl;
    return 0;
}