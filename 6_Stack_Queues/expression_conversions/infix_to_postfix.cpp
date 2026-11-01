#include <iostream>
#include <stack>
using namespace std;

int priority(char ch)
{
    if (ch == '^')
        return 3;
    else if ((ch == '*') || (ch == '/'))
        return 2;
    else if ((ch == '+') || (ch == '-'))
        return 1;
    else
        return -1;
}

string infixToPostfix(string s)
{
    // code here
    int i = 0, n = s.length();
    string ans = "";
    stack<char> st;

    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            if (!st.empty())
            {
                st.pop();
            }
        }
        // left-associativity
        else
        {
            while (!st.empty() && st.top() != '(' && (priority(s[i]) < priority(st.top()) || (priority(s[i]) == priority(st.top()) && st.top() != '^')))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    cout << infixToPostfix("a+b-c") << endl;
    cout << infixToPostfix("a^b^c") << endl;
    return 0;
}