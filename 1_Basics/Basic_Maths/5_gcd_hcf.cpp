#include <iostream>
#include <math.h>
using namespace std;

void gcdd(int num1, int num2)
{
    while (num1 > 0 && num2 > 0)
    {
        if (num1 > num2)
        {
            num1 = num1 % num2; // % - remainder
        }
        else // number which is greater will get % with smaller one and stored
        // in bigger one
        {
            num2 = num2 % num1;
        }
    }

    if (num1 == 0)
    {
        cout << num2 << endl;
    }
    else
    {
        cout << num1 << endl;
    }
}

int main()
{
    int num1, num2, gcd = 1;

    cin >> num1 >> num2;

    // T.C. = O(min(num1,num2))
    // same complexity for :
    /*

    for (int i = min(num1, num2); i <= 1; i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            print i;
            break;
        }
    }

    */

    for (int i = 1; i <= min(num1, num2); i++)
    {
        if (num1 % i == 0 && num2 % i == 0)
        {
            gcd = i;
        }
    }

    cout << gcd << endl;

    // we can do in minimum time complxity using euclidean algorithm
    // gcd(n1,n2) = gcd(n1-n2,n2) where n1>n2  n1-n2

    // but gcd(n1-n2,n2) miht take a lot of time (52,10)
    // so simply we use gcd(n1%n2,n2) to reach last step of n1-n2 (before swapping)

    // until 1 number is 0 keep on truncating
    // non-zero number at end is gcd of both number

    gcdd(num1, num2); // T.C. = O(log(phi) min(num1,num2))

    return 0;
}