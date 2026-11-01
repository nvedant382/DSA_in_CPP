#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    vector<int> arr3(n + m);

    int left = 0;
    int right = 0;
    int index = 0;

    while (left < n && right < m)
    {
        if (arr1[left] <= arr2[right])
        {
            arr3[index] = arr1[left];
            left++;
            index++;
        }
        else
        {
            arr3[index] = arr2[right];
            index++;
            right++;
        }
    }

    while (left < n)
    {
        arr3[index++] = arr1[left++];
    }

    while (right < m)
    {
        arr3[index++] = arr2[right++];
    }
    // put back elements in original array

    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr3[i];
    }

    for (int i = n; i < n + m; i++)
    {
        arr2[i - n] = arr3[i];
    }

    for (int i = 0; i < n + m; i++)
    {
        if (i < n)
            cout << arr1[i] << " ";
        else
        {
            cout << arr2[i - n] << " ";
        }
    }
    cout << endl;
}

void merge_optimal_1(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (arr1[left] > arr2[right])
        {
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

void swapIfGreater(vector<int> &arr1, vector<int> &arr2, int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}

void merge_optimal_2(vector<int> arr1, vector<int> arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    int len = n + m;
    int gap = (len / 2) + (len % 2); // 4 + 1(ceiling 1)

    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;

        while (right < len)
        {
            // we are comparing in arr1 and arr2
            if (left < n && right >= n)
            {
                // right - n bez to be in correct position
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // we are comparing in arr2 and arr2
            else if (left >= n)
            {
                // - n to make sure indexes are correctly in arr2
                swapIfGreater(arr1, arr2, left - n, right - n);
            }
            // we are comparing in arr1 and arr1
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            right++;
            left++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < m; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

/*

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1;
        int j = n-1;
        int k = m+n-1;

        while(i>=0 && j>=0){
            if(nums2[j]>nums1[i]){
                nums1[k] = nums2[j];
                k--;
                j--;
            }else{
                nums1[k] = nums1[i];
                k--;
                i--;
            }
        }

        while(j>=0){
            nums1[k] = nums2[j];
            k--;j--;
        }
    }
};

*/

int main()
{
    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};
    merge(arr1, arr2);
    merge_optimal_1(arr1, arr2);
    merge_optimal_2(arr1, arr2);
    return 0;
}