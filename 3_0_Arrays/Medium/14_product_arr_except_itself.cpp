#include <iostream>
#include <vector>
using namespace std;
// O(N^2)
void productExceptSelf(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j != i)
                ans[i] *= arr[j];
        }
    }

    // --------------

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

// O(3N) and O(N)
void productExceptSelf_better(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);
    vector<int> pre(n, 1);
    vector<int> suff(n, 1);

    pre[0] = 1;
    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] * arr[i - 1];
    }

    suff[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suff[i] = suff[i + 1] * arr[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        ans[i] = suff[i] * pre[i];
    }

    // --------------

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

// Optimizing Space complexity
/*
    Do we actually need prefix/suffix array ??
    cause we know arr(i) = prefix(i) * suffix(i)

    instead of storing we will directly store or multiply in arr(i)
*/
// O(N^2)  and  O(1)
void productExceptSelf_optimal(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n, 1);

    // calculate prefix in ans array
    for (int i = 1; i < n; i++)
    {
        ans[i] = ans[i - 1] * arr[i - 1];
    }
    // ans will contain all prefixes

    int suffix = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        suffix *= arr[i + 1];
        ans[i] *= suffix;
    }

    // --------------

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    vector<int> arr = {1, 2, 3, 4};
    productExceptSelf(arr);
    productExceptSelf_better(arr);
    productExceptSelf_optimal(arr);
    return 0;
}