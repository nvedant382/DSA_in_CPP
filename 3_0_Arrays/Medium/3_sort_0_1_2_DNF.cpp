#include <iostream>
#include <vector>
using namespace std;

void sortColors(int arr[], int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)

            cnt0++;
        else if (arr[i] == 1)
            cnt1++;
        else
            cnt2++;
    }

    for (int i = 0; i < cnt0; i++)
        arr[i] = 0;
    for (int i = cnt0; i < cnt0 + cnt1; i++)
        arr[i] = 1;
    for (int i = cnt0 + cnt1; i < n; i++)
        arr[i] = 2;
}

// dutch national flag algorithm
void DNF(int arr[], int n)
{
    int low = 0, mid = 0, high = n - 1;
    // until there is unsorted part
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
            mid++;
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};

    DNF(arr, 12);

    for (int i = 0; i < 12; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}