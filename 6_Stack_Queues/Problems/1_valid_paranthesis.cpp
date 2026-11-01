#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(string s)
{
    stack<int> st;
    int n = s.length();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.empty())
                return false;

            char top = st.top();
            st.pop();

            if ((s[i] == ']' && top == '[') || (s[i] == '}' && top == '{') || (s[i] == ')' && top == '('))
            {
                ;
            }
            else
            {
                return false;
            }
        }
    }

    return st.empty();
}

int main()
{
    cout << isValid("))") << endl;
    cout << isValid("((]") << endl;
    cout << isValid("(){}[]") << endl;
    cout << isValid("({[]})") << endl;
    return 0;
}