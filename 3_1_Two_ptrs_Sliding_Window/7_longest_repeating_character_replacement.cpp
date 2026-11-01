#include <iostream>
#include <string>
using namespace std;

int longest_repeating(string s, int k)
{
    int n = s.length(), maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int hash[26] = {0}, maxf = 0;
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'A']++;

            maxf = max(maxf, hash[s[j] - 'A']);

            if (((j - i + 1) - maxf) > k)
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

int longest_repeating_opt(string s, int k)
{
    int n = s.length(), maxLen = 0, r = 0, l = 0, hash[26] = {0}, maxf = 0;

    while (r < n)
    {
        hash[s[r] - 'A']++;
        maxf = max(maxf, hash[s[r] - 'A']);

        // can use if instead of while for optimization to 2N -> N
        while (((r - l + 1) - maxf) > k)
        {
            hash[s[l] - 'A']--;

            // here maxf may get lower then it's current value
            // but we want max length answer so we will keep maxf as it is,
            // and so the Length, until we get another larger substring
            /* maxf = 0;
            for (int i = 0; i < 26; i++)
            {
                maxf = max(maxf, hash[i]);
            } */

            l++;
        }

        if (((r - l + 1) - maxf) <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }

        r++;
    }

    return maxLen;
}

int main()
{
    string s = "AAABBCCD";
    cout << longest_repeating(s, 2) << endl;
    cout << longest_repeating_opt(s, 2) << endl;
    return 0;
}