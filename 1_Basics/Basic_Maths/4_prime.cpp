#include <iostream>
#include <math.h>
using namespace std;
// Prime :-> Divisible by 1 and itself
// Bruce Force:-> T.C. = O(N) by using counter using divisors logic
// T.C. = O(sqrt(N)) by using divisors logic + counter==2
int main()
{
    int num, cnt = 0;
    cin >> num;

    for (int i = 1; i * i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            cnt++;
            if ((num / i) != i)
            {
                cnt++;
            }
        }
    }

    if (cnt == 2)
    {
        cout << num << " Prime Number" << endl;
    }
    else
    {
        cout << num << " Not a Prime Number" << endl;
    }

    return 0;
}