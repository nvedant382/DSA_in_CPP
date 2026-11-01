#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElements(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        bool found = false;
        int nge = -1;

        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] > nums[i])
            {
                found = true;
                nge = nums[j];
                break;
            }
        }

        if (!found)
        {
            for (int k = 0; k <= i - 1; k++)
            {
                if (nums[k] > nums[i])
                {
                    nge = nums[k];
                    break;
                }
            }
        };

        ans.push_back(nge);
    }
    return ans;
}

vector<int> nextGreaterElements_same(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int nge = -1;
        for (int j = i + 1; j < i + n; j++)
        {
            int idx = j % n;
            if (nums[idx] > nums[i])
            {
                nge = nums[idx];
                break;
            }
        }
        ans.push_back(nge);
    }

    return ans;
}

vector<int> nextGreaterElements_optimal(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n);
    stack<int> st;

    for (int i = 2 * n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i % n])
        {
            st.pop();
        }

        if (i < n)
        {
            ans[i] = st.empty() ? -1 : st.top();
        }

        st.push(nums[i % n]);
    }

    return ans;
}

int main()
{
    vector<int> ans = nextGreaterElements({1, 2, 3, 4, 3});
    for (int el : ans)
    {
        cout << el << " ";
    }
    cout << endl;

    vector<int> ans2 = nextGreaterElements_same({1, 2, 3, 4, 3});
    for (int el : ans2)
    {
        cout << el << " ";
    }
    cout << endl;

    vector<int> ans3 = nextGreaterElements_optimal({1, 2, 3, 4, 3});
    for (int el : ans3)
    {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}