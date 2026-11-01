#include <iostream>
using namespace std;
// T.C. = Q * O(N) N is size of array, Q amount of numbers for calling function
// 10^5 * 10^5 = 10^10 which means 100 sec to execute a program
// cause 10^8 operations ~ 1 second
int freq(int number, int a[], int n)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] == number)
        {
            cnt++;
        }
    }

    return cnt;
}

int main()
{
    int a[] = {1, 2, 1, 3, 5, 5, 4};
    int size = sizeof(a) / sizeof(a[0]);

    cout << freq(5, a, size) << endl;
    cout << freq(3, a, size) << endl;
    cout << freq(1, a, size) << endl;

    return 0;
}