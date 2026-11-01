#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int maxSubstringWithKUnique(string s, int k)
{
    int n = s.length(), maxLen = 0;
    set<int> st;

    for (int i = 0; i < n; i++)
    {
        st.clear();
        for (int j = i; j < n; j++)
        {
            st.insert(s[j]);
            if (st.size() > k)
            {
                break;
            }
            else
            {
                maxLen = max(maxLen, j - i + 1);
            }
        }
    }

    return maxLen;
}

int maxSubstringWithKUnique_opt(string s, int k)
{
    int n = s.length(), maxLen = 0, l = 0, r = 0;
    map<int, int> mpp;

    while (r < n)
    {
        mpp[s[r]]++;

        if (mpp.size() > k)
        {
            mpp[s[l]]--;
            if (mpp[s[l]] == 0)
            {
                mpp.erase(s[l]);
            }
            l++;
        }
        else
        {
            maxLen = max(maxLen, r - l + 1);
        }

        r++;
    }

    return maxLen;
}

int main()
{
    string str = "aaabbccd";
    cout << maxSubstringWithKUnique(str, 2) << endl;
    cout << maxSubstringWithKUnique(str, 2) << endl;
    return 0;
}