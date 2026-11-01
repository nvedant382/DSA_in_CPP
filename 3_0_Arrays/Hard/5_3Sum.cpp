#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> ThreeSum(vector<int> &arr)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> ThreeSum_better(vector<int> &arr)
{
    int n = arr.size();

    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(arr[i] + arr[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> ThreeSum_optimal(vector<int> &arr)
{
    int n = arr.size();
    vector<vector<int>> ans;

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (arr[j] == arr[j - 1])
                    j++;
                while (arr[k] == arr[k + 1])
                    k--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = ThreeSum(arr);

    for (auto triplet : ans)
    {
        for (auto ele : triplet)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "---------------" << endl;

    vector<vector<int>> ans2 = ThreeSum_better(arr);

    for (auto triplet : ans2)
    {
        for (auto ele : triplet)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "---------------" << endl;

    vector<vector<int>> ans3 = ThreeSum_optimal(arr);

    for (auto triplet : ans3)
    {
        for (auto ele : triplet)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}