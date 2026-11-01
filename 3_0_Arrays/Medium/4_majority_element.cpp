#include <iostream>
#include <map>
using namespace std;

int majorityElement(int arr[], int n)
{
    // Time = O(N^2)
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                cnt++;
            }
        }
        if (cnt > n / 2)
        {
            return arr[i];
        }
    }
    return -1;
}

int majorityElement_better(int arr[], int n)
{
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // iterate in MAP
    for (auto it : mpp)
    {
        if (it.second > (n / 2))
        {
            return it.first;
        }
    }

    return -1;
}

int moore_voting_algo(int arr[], int n)
{
    int cnt = 0;
    int el;

    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        { // if cnt is 0 , then consider new element as new majority
            cnt = 1;
            el = arr[i];
        }
        else if (arr[i] == el)
            cnt++;
        else
            cnt--;
    }

    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el == arr[i])
        {
            cnt1++;
        }
    }

    if (cnt1 > (n / 2))
    {
        return el;
    }

    return -1;
}

int main()
{
    int arr[] = {2, 2, 3, 3, 1, 2, 2};
    cout << majorityElement(arr, 7) << endl;
    cout << majorityElement_better(arr, 7) << endl;
    cout << moore_voting_algo(arr, 7) << endl;
    return 0;
}