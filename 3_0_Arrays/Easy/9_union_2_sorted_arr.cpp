#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> findUnion(int arr1[], int n1, int arr2[], int n2)
{
    set<int> st;
    for (int i = 0; i < n1; i++)
    {
        st.insert(arr1[i]);
    }

    for (int i = 0; i < n2; i++)
    {
        st.insert(arr2[i]);
    }

    vector<int> unionn;

    for (auto it : st)
    {
        unionn.push_back(it);
    }

    return unionn;
}

/*


class Solution {
public:
    vector<int> unionOfArrays(vector<int>& nums1, vector<int>& nums2) {
        const int RANGE = 1001; // Adjust based on known range
        vector<bool> present(RANGE, false);
        vector<int> unionArray;

        // Mark numbers from both arrays
        for (int num : nums1) {
            present[num] = true;
        }
        for (int num : nums2) {
            present[num] = true;
        }

        // Gather the union
        for (int i = 0; i < RANGE; i++) {
            if (present[i]) {
                unionArray.push_back(i);
            }
        }
        return unionArray;
    }
};

-------->>>>>>>>    NOT UNIVERSAL though;

*/

vector<int> findUnion_opt(int arr1[], int n1, int arr2[], int n2)
{
    int i = 0;
    int j = 0;

    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != arr1[i])
            {
                unionArr.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != arr2[j])
            {
                unionArr.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr1[i])
        {
            unionArr.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != arr2[j])
        {
            unionArr.push_back(arr2[j]);
        }
        j++;
    }

    return unionArr;
}

int main()
{
    int arr1[] = {1, 1, 2, 3, 4, 5};
    int arr2[] = {2, 3, 4, 4, 5};

    vector<int> unionn = findUnion(arr1, 6, arr2, 5);

    for (int i = 0; i < unionn.size(); i++)
    {
        cout << unionn[i] << " ";
    }

    vector<int> unionn2 = findUnion(arr1, 6, arr2, 5);

    for (int i = 0; i < unionn2.size(); i++)
    {
        cout << unionn2[i] << " ";
    }

    return 0;
}