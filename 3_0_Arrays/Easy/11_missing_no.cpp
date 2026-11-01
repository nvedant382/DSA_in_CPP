#include <iostream>
#include <vector>
using namespace std;

int missingNumber(vector<int> nums)
{
    int n = nums.size();

    vector<int> hash(n + 1, 0);

    for (int i = 0; i < n; i++)
    {
        hash[nums[i]]++;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }

    return -1;
}

// Optimal
/*

int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int xor1=0,xor2=0;

        for(int i=0;i<n;i++){
            xor1 = xor1^i;
            xor2 = xor2 ^ nums[i] ;
        }

        xor1 = xor1 ^ n;

        return (xor1^xor2);
    }

*/

/*

int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int sum = (n*(n+1))/2;
        int sum2 = 0;

        for(int i=0;i<n;i++){
            sum2+=nums[i];
        }

        return sum-sum2;
    }

*/

int main()
{
    vector<int> arr = {1, 2, 4, 5};

    cout << missingNumber(arr) << endl;

    // for (int i = 0; i <= n; i++)
    // {
    //     int flag = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == arr[j])
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         cout << i;
    //     }
    // }

    return 0;
}