#include <iostream>
using namespace std;

void f(int i, int sum)
{
    if (i < 1)
    {
        cout << sum << endl;
        return;
    }
    f(i - 1, sum + i);
}

int f2(int n)
{
    if (n == 0)
        return 0;
    return n + f2(n - 1);
}

int main()
{
    int n;
    cin >> n;
    f(n, 0);

    cout << f2(n) << endl;

    return 0;
}