#include <iostream>
#include <vector>
using namespace std;

vector<int> intersectArrays(int a[], int n1, int b[], int n2)
{
    vector<int> vis(n2, 0);
    vector<int> ans;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (a[i] == b[j] && vis[j] == 0)
            {
                ans.push_back(a[i]);
                vis[j] = 1;
                break;
            }

            if (b[j] > a[i])
            {
                break;
            }
        }
    }

    return ans;
}

// Optimal
vector<int> intersectArrays_opt(int a[], int n1, int b[], int n2)
{
    int i = 0;
    int j = 0;
    vector<int> ans;

    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (a[i] > b[j])
        {
            j++;
        }
        else
        {
            ans.push_back(arr[i]);
            i++;
            j++;
        }
    }

    return ans;
}

/* intersection of unsorted arrays

vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> set1(nums1.begin(),nums1.end());
        unordered_set<int> res;

        for(auto num:nums2){
            if(set1.count(num)){
                res.insert(num);
            }
        }

        return vector<int>(res.begin(),res.end());
    }
*/

int main()
{
    int a[] = {1, 2, 2, 3, 3, 4, 5, 6};
    int b[] = {2, 3, 3, 5, 6, 6, 7};

    vector<int> ans = intersectArrays(a, 8, b, 7);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    vector<int> ans2 = intersectArrays_opt(a, 8, b, 7);

    for (int i = 0; i < ans2.size(); i++)
    {
        cout << ans2[i] << " ";
    }

    return 0;
}