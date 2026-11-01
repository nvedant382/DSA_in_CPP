#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<vector<int>> FourSum(vector<int> &arr, int target)
{
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] + arr[l] == target)
                    {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> FourSum_better(vector<int> &arr, int target)
{
    int n = arr.size();

    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            set<int> hashset;
            for (int k = j + 1; k < n; k++)
            {
                int fourth = target - (arr[i] + arr[j] + arr[k]);
                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> FourSum_optimal(vector<int> &arr, int target)
{
    int n = arr.size();

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && arr[j] == arr[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;

            while (k < l)
            {
                int sum = arr[i] + arr[j] + arr[k] + arr[l];
                if (sum < target)
                {
                    k++;
                }
                else if (sum > target)
                {
                    l--;
                }
                else
                {
                    ans.push_back({arr[i], arr[j], arr[k], arr[l]});
                    k++;
                    l--;

                    while (k < l && arr[k] == arr[k - 1])
                        k++;
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = FourSum(arr, 0);

    for (auto quad : ans)
    {
        for (auto ele : quad)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "---------------" << endl;

    vector<vector<int>> ans2 = FourSum_better(arr, 0);

    for (auto triplet : ans2)
    {
        for (auto ele : triplet)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "---------------" << endl;

    vector<vector<int>> ans3 = FourSum_optimal(arr, 0);

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