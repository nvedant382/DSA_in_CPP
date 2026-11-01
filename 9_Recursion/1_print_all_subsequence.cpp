#include <iostream>
#include <climits>
#include <vector>
using namespace std;

void generateAllSequences(int idx, vector<int> &arr, vector<int> &ans)
{
    if (idx == arr.size())
    {
        for (auto ele : ans)
        {
            cout << ele << " ";
        }
        cout << endl;
        return;
    }

    // take
    ans.push_back(arr[idx]);
    generateAllSequences(idx + 1, arr, ans);

    // not take
    ans.pop_back();
    generateAllSequences(idx + 1, arr, ans);
}

int main()
{
    vector<int> arr = {3, 1, 2};
    vector<int> ans = {};
    generateAllSequences(0, arr, ans);
    return 0;
}