#include <iostream>
#include <vector>
using namespace std;

int totalTrappedWater(vector<int> &height)
{
    int n = height.size();
    vector<int> prefix(n), suffix(n);

    prefix[0] = height[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], height[i]);
    }

    suffix[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], height[i]);
    }

    int total = 0;

    for (int i = 0; i < n; i++)
    {
        int leftMax = prefix[i];
        int rightMax = suffix[i];

        if (height[i] < leftMax && height[i] < rightMax)
        {
            total += (min(leftMax, rightMax) - height[i]);
        }
    }

    return total;
}

int totalTrappedWater_optimal(vector<int> &height)
{
    int n = height.size();
    int left_max = 0, right_max = 0; // tracking maximum of both sides
    int left = 0, right = n - 1;     // pointers
    int total = 0;                   // answer

    while (left < right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] > left_max)
            {
                left_max = height[left];
            }
            else
            {
                total += (left_max - height[left]);
            }
            left++;
        }
        else
        {
            if (height[right] > right_max)
            {
                right_max = height[right];
            }
            else
            {
                total += (right_max - height[right]);
            }
            right--;
        }
    }

    return total;
}

int main()
{
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << totalTrappedWater(height) << endl;
    cout << totalTrappedWater_optimal(height) << endl;
    return 0;
}