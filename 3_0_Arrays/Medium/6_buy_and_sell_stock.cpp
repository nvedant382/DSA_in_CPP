#include <iostream>
using namespace std;

int buyAndSellStock(int arr[], int n)
{
    int profit = 0;
    int mini = arr[0];

    for (int i = 1; i < n; i++)
    {
        int cost = arr[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, arr[i]);
    }

    return profit;
}

int main()
{
    int arr[] = {7, 1, 5, 3, 6, 4};
    cout << buyAndSellStock(arr, 6) << endl;
    return 0;
}