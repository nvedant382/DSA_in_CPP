#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*

void reverseArray(vector<int> &arr, int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

*/

vector<int> next_permutation(vector<int> arr)
{
    int n = arr.size();
    int idx = -1;

    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            idx = i;
            break;
        }
    }

    if (idx == -1)
    {
        reverse(arr.begin(), arr.end());
        return arr;
    }

    for (int i = n - 1; i > idx; i--)
    {
        if (arr[i] > arr[idx])
        {
            swap(arr[i], arr[idx]);
            break;
        }
    }

    // sort it , but reverse it was already in incresing curve
    reverse(arr.begin() + idx + 1, arr.end());

    return arr;
}

int main()
{
    vector<int> arr = {2, 1, 5, 4, 3, 0, 0};
    // T.C. = O(3N)
    vector<int> ans = next_permutation(arr);

    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}