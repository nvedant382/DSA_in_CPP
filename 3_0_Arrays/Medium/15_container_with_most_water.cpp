#include <iostream>
#include <vector>
using namespace std;

void MostWater(vector<int> &height)
{
    int maxW = 0;

    for (int i = 0; i < height.size(); i++)
    {
        for (int j = i + 1; j < height.size(); j++)
        {
            int w = j - i;
            int ht = min(height[j], height[i]);

            maxW = max(maxW, w * ht);
        }
    }

    cout << maxW << endl;
}

void MostWater_optimal(vector<int> &height)
{
    int n = height.size();

    int lp = 0, rp = n - 1, maxW = 0;

    while (lp < rp)
    {
        int w = rp - lp;
        int ht = min(height[lp], height[rp]);

        maxW = max(maxW, w * ht);

        height[lp] < height[rp] ? lp++ : rp--;
    }

    cout << maxW << endl;
}

int main()
{
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    MostWater(height);
    MostWater_optimal(height);

    return 0;
}