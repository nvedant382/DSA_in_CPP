#include <iostream>
#include <stack>
#include <string>
using namespace std;

string postfix_to_prefix(string s)
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
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push(s[i] + t2 + t1);
        }
        i++;
    }

    return st.top();
}

int main()
{
    cout << postfix_to_prefix("AB-DE+F*/") << endl;
    return 0;
}