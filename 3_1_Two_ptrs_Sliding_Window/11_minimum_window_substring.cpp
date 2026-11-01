#include <iostream>
#include <string>
#include <climits>
using namespace std;

string minimum_window_substring(string s, string t)
{
    if (t.length() > s.length())
        return "";

    int n = s.length(), m = t.length(), minLen = INT_MAX, startIdx = -1;

    for (int i = 0; i < n; i++)
    {
        int hash[256] = {0}, cnt = 0;

        for (int j = 0; j < m; j++)
        {
            hash[t[j]]++;
        }

        for (int j = i; j < n; j++)
        {
            if (hash[s[j]] > 0)
                cnt++;

            hash[s[j]]--;

            if (cnt == m)
            {
                if ((j - i + 1) < minLen)
                {
                    minLen = j - i + 1;
                    startIdx = i;
                }
                break;
            }
        }
    }

    if (startIdx == -1)
        return "";

    return s.substr(startIdx, minLen);
}

string minimum_window_substring_opt(string s, string t)
{
    if (t.length() > s.length())
        return "";

    int n = s.length(), m = t.length(), minLen = INT_MAX, startIdx = -1, r = 0, l = 0;
    int hash[256] = {0}, cnt = 0;

    for (int i = 0; i < m; i++)
    {
        hash[t[i]]++;
    }

    while (r < n)
    {
        if (hash[s[r]] > 0)
            cnt++;

        hash[s[r]]--;

        while (cnt == m)
        {
            if ((r - l + 1) < minLen)
            {
                minLen = r - l + 1;
                startIdx = l;
            }

            hash[s[l]]++;
            if (hash[s[l]] > 0)
            {
                cnt--;
            }
            l++;
        }

        r++;
    }

    if (startIdx == -1)
        return "";

    return s.substr(startIdx, minLen);
}

int main()
{
    string s = "ddaaabbca";
    string t = "abc";
    cout << minimum_window_substring(s, t) << endl;
    cout << minimum_window_substring_opt(s, t) << endl;
    return 0;
}