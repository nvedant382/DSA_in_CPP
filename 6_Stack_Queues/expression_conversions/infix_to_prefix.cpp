#include <iostream>
#include <stack>
#include <algorithm>
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

string reverse(string &s)
{
    reverse(s.begin(), s.end());

    // Step 2: Swap the parentheses
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            s[i] = ')';
        }
        else if (s[i] == ')')
        {
            s[i] = '(';
        }
    }

    return s;
}

string infixToPrefix(string s)
{
    // 1. Reverse the string and swap parentheses
    reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            s[i] = ')';
        else if (s[i] == ')')
            s[i] = '(';
    }

    string ans = "";
    stack<char> st;

    // 2. Find the postfix expression of the modified string
    for (int i = 0; i < s.length(); i++)
    {
        // If it's an operand, add it to the answer
        if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        // If it's an opening parenthesis, push it
        else if (s[i] == '(')
        {
            st.push(s[i]); // PUSH IS CORRECTLY PLACED HERE
        }
        // If it's a closing parenthesis, pop until you see '('
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())
                st.pop(); // Pop the opening paren
        }
        // If it's an operator
        else
        {
            // Use correct associativity for reversed string
            // '^' (originally R-to-L) is treated as L-to-R
            if (s[i] == '^')
            {
                while (!st.empty() && priority(s[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            // Other ops (originally L-to-R) are treated as R-to-L
            else
            {
                while (!st.empty() && priority(s[i]) < priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            st.push(s[i]); // PUSH IS CORRECTLY PLACED HERE
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // 3. Reverse the final answer to get the prefix expression
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    cout << infixToPrefix("a+b-c") << endl;
    cout << infixToPrefix("a^b^c") << endl;
    return 0;
}