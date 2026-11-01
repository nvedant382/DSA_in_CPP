#include <iostream>
#include <string>
using namespace std;

int No_of_substrings(string s)
{
    int n = s.length(), cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int hash[3] = {0, 0, 0};
        for (int j = i; j < n; j++)
        {
            hash[s[j] - 'a'] = 1;

            if (hash[0] + hash[1] + hash[2] == 3)
            {
                // cnt++;
                cnt += (n - j); // optimization
                break;
            }
        }
    }
    return cnt;
}

int No_of_substrings_opt(string s)
{
    int n = s.length(), cnt = 0;
    int lastSeen[3] = {-1, -1, -1};

    for (int i = 0; i < n; i++)
    {
        lastSeen[s[i] - 'a'] = i;

        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            cnt += (1 + min(min(lastSeen[0], lastSeen[1]), lastSeen[2]));
        }
    }

    return cnt;
}

int main()
{
    string s = "bbacba";
    cout << No_of_substrings(s) << endl;
    return 0;
}