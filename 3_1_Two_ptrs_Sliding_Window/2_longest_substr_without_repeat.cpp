#include <iostream>
#include <vector>
#include <string>
using namespace std;

int longestSubString(string s)
{
    int n = s.length();
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int hash[256] = {0};
        for (int j = i; j < n; j++)
        {
            if (hash[s[j]] == 1)
                break;

            int len = j - i + 1;
            maxLen = max(maxLen, len);
            hash[s[j]]++;
        }
    }

    return maxLen;
}

int longestSubString_opt(string s)
{
    int n = s.length();

    int l = 0, r = 0, maxLen = 0;
    vector<int> hash(256, -1);

    while (r < n)
    {
        if (hash[s[r]] != -1)
        {
            if (hash[s[r]] >= l)
            {
                l = hash[s[r]] + 1;
            }
        }

        int len = r - l + 1;
        maxLen = max(maxLen, len);
        hash[s[r]] = r;
        r++;
    }

    return maxLen;
}

int main()
{
    string str = "cadbzabcd";
    cout << longestSubString(str) << endl;
    cout << longestSubString_opt(str) << endl;
    return 0;
}