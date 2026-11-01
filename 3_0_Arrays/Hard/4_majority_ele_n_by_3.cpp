#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
using namespace std;

vector<int> majEle(vector<int> nums)
{
    int n = nums.size();
    vector<int> ls;

    for (int i = 0; i < n; i++)
    {
        if (ls.size() == 0 || ls[0] != nums[i])
        {
            int cnt = 0;
            for (int j = 0; j < n; j++)
            {
                if (nums[i] == nums[j])
                    cnt++;
            }

            if (cnt > n / 3)
            {
                ls.push_back(nums[i]);
            }
        }

        if (ls.size() == 2)
            break;
    }
    return ls;
}

vector<int> majorityElement(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ls;
    map<int, int> mpp;
    int mini = (int)n / 3 + 1;

    for (int i = 0; i < n; i++)
    {
        mpp[nums[i]]++;

        if (mpp[nums[i]] == mini)
        {
            ls.push_back(nums[i]);
        }

        if (ls.size() == 2)
            break;
    }

    sort(ls.begin(), ls.end());
    return ls;
}

vector<int> maj_opt(vector<int> &nums)
{
    int n = nums.size();
    int cnt1 = 0, cnt2 = 0, el1 = INT_MIN, el2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (cnt1 == 0 && nums[i] != el2)
        {
            cnt1 = 1;
            el1 = nums[i];
        }
        else if (cnt2 == 0 && nums[i] != el1)
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if (nums[i] == el1)
            cnt1++;
        else if (nums[i] == el2)
            cnt2++;
        else
            cnt1--, cnt2--;
    }

    vector<int> ls;
    cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (el1 == nums[i])
            cnt1++;
        else if (el2 == nums[i])
            cnt2++;
    }

    int mini = (int)(n / 3) + 1;
    if (cnt1 >= mini)
        ls.push_back(el1);
    if (cnt2 >= mini)
        ls.push_back(el2);

    sort(ls.begin(), ls.end());
    return ls;
}

int main()
{
    vector<int> arr = {1, 1, 1, 3, 3, 2, 2, 2};

    // vector<int> ls = majEle(arr);
    // for (auto ele : ls)
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;

    vector<int> ls2 = maj_opt(arr);
    for (auto ele : ls2)
    {
        cout << ele << " ";
    }
    cout << endl;
    return 0;
}