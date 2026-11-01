#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterElement(vector<int> nums)
{
    int n = nums.size();
    stack<int> st;
    vector<int> ans(n);

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && st.top() <= nums[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        st.push(nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> ans = nextGreaterElement({4, 8, 5, 2, 25});
    for (int el : ans)
    {
        cout << el << " ";
    }
    cout << endl;
    return 0;
}