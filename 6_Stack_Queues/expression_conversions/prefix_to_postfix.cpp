#include <iostream>
#include <stack>
#include <string>
using namespace std;

string prefix_to_postfix(string s)
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
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();

            st.push(t1 + t2 + s[i]);
        }
        i--;
    }

    return st.top();
}

int main()
{
    cout << prefix_to_postfix("/-AB*+DEF") << endl;
    return 0;
}