#include <iostream>
using namespace std;
// T.C. = O(2^n) every func() is calling 2 func()'s
// therefore , it is exponential in nature
int fibo(int n)
{
    if (n <= 1)
        return n; // 0 and 1

    int last = fibo(n - 1);
    int slast = fibo(n - 2);

    return last + slast;
}

int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;

    int a = 0;
    int b = 1;
    cout << a << " ";
    for (int i = 2; i <= n; i++)
    {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }

    return 0;
}