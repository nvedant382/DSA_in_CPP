#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

string removeKDigit(string s, int k)
{
    int n = s.size();
    stack<char> st;

    if (k == n)
        return "0";

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && k > 0 && st.top() > s[i])
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }

    while (k > 0)
    {
        st.pop();
        k--;
    }

    if (st.empty())
        return "0";

    string res = "";
    while (!st.empty())
    {
        res = res + st.top();
        st.pop();
    }

    while (res.size() != 0 && res.back() == '0')
    {
        res.pop_back();
    }

    if (res.empty())
        return "0";

    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    string s = "1432219";
    cout << removeKDigit(s, 3) << endl;
    return 0;
}