#include <iostream>
#include <vector>
using namespace std;

void moveZerosToEnd(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
        return;

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[j], arr[i]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {1, 0, 2, 0, 0, 0, 3, 0, 4};

    moveZerosToEnd(arr, 9);

    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}