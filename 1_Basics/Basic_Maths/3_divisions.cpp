#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // T.C. = O(sqrt(n))
    // i <= sqrt(n)
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << endl;
            if ((n / i) != i) // to avoid duplicates like n/6 = 6 so n/i != i
            { 
                cout << (n / i) << endl;
            }
        }
    }

    return 0;
}