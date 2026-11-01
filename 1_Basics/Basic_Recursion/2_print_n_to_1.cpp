#include <iostream>
using namespace std;
/*

T.C. = O(N) calling function N times

S.C. = O(N) stack space (internal memory)

*/
void f(int n, int i)
{
    if (i > n)
        return;
    cout << n << " ";
    f(n - 1, i); // not n-- it will go infinite (n-- / --n will change actual n)
}

int main()
{
    int n;
    cin >> n;
    f(n, 1);
    return 0;
}