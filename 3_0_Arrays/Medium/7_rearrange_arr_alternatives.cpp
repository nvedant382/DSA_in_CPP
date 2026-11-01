#include <iostream>
#include <vector>
using namespace std;

vector<int> reArrange(vector<int> nums)
{
    int n = nums.size();
    vector<int> ans(n);

    int posIdx = 0;
    int negIdx = 1;

    for (int i = 0; i < n; i++)
    {
        if (nums[i] < 0)
        {
            ans[negIdx] = nums[i];
            negIdx += 2;
        }
        else
        {
            ans[posIdx] = nums[i];
            posIdx += 2;
        }
    }

    return ans;
}

vector<int> reArrange_var2(vector<int> nums)
{
    int n = nums.size();
    vector<int> neg;
    vector<int> pos;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            pos.push_back(nums[i]);
        }
        else
        {
            neg.push_back(nums[i]);
        }
    }

    if (pos.size() > neg.size())
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    else
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[2 * i] = pos[i];
            arr[2 * i + 1] = neg[i];
        }

        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }

    return arr;
}

int main()
{
    vector<int> arr = {3, 1, -2, -5, 2, -4};
    vector<int> ans = reArrange(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    cout << endl;

    vector<int> arr2 = {3, 1, -2, -5, 2, -4, 7, 10};
    vector<int> ans2 = reArrange_var2(arr2);

    for (auto it : ans2)
    {
        cout << it << " ";
    }
    return 0;
}