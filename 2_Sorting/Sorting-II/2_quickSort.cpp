#include <iostream>
using namespace std;

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        // i will find larger element than pivot
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }
        // j will find lesser element than pivot
        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j; // new index of pivot
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) // for atomic value if() will not execute ex.(0<0)
    {
        int pindex = partition(arr, low, high);
        quickSort(arr, low, pindex - 1);
        quickSort(arr, pindex + 1, high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*

Why swap(pivot, arr[j]); gives the wrong answer?

swap(pivot, arr[j]);

you are not swapping the actual array element—you're just swapping the
local variable pivot (which holds a copy of arr[low]) with arr[j].
This does not modify arr[low], which means the pivot remains unchanged in the array.

*/