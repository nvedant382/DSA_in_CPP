#include <iostream>
using namespace std;

int main()
{
    int arr[] = {1, 6, 4, 8, 9, 10, 3, 2};
    int x;
    cin >> x;

    for (int i = 0; i < 8; i++)
    {
        if (arr[i] == x)
        {
            cout << i;
        }
    }

    return 0;
}