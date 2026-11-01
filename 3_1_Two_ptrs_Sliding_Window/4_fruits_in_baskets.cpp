#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

int max_no_of_fruits(vector<int> &fruits)
{
    int n = fruits.size(), maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(fruits[j]);

            if (st.size() > 2)
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

int max_no_of_fruits_opt(vector<int> &fruits)
{
    int n = fruits.size(), l = 0, r = 0, maxLen = 0;
    map<int, int> mpp;

    while (r < n)
    {
        mpp[fruits[r]]++;

        if (mpp.size() <= 2)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        else
        {
            while (mpp.size() > 2)
            {
                mpp[fruits[l]]--;
                if (mpp[fruits[l]] == 0)
                {
                    mpp.erase(fruits[l]);
                }
                l++;
            }
        }
 
        r++;
    }

    return maxLen;
}

int main()
{
    vector<int> fruits = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << max_no_of_fruits(fruits) << endl;
    cout << max_no_of_fruits_opt(fruits) << endl;
    return 0;
}