#include <iostream>
#include <unordered_map>
#include <climits>
using namespace std;

int main()
{
    int arr[] = {1, 2, 1, 2, 3, 4, 3, 1};
    unordered_map<int, int> mpp;

    for (int i = 0; i < 8; i++)
    {
        mpp[arr[i]]++;
    }

    int minFreq = INT_MAX;
    int maxFreq = INT_MIN;

    int maxEle = -1, minEle = -1;

    for (auto it : mpp)
    {
        if (it.second > maxFreq)
        {
            maxFreq = it.second;
            maxEle = it.first;
        }

        if (it.second < minFreq)
        {
            minFreq = it.second;
            minEle = it.first;
        }
    }

    cout << maxEle << " " << minEle << endl;

    return 0;
}