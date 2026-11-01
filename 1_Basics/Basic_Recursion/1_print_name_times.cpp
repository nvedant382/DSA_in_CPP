#include <iostream>
using namespace std;
/*

T.C. = O(N) calling function N times

S.C. = O(N) stack space (internal memory)

*/
void f(int i, int n)
{
    if (i > n)
        return;
    cout << "Vedant" << endl;
    f(i + 1, n);
}

int main()
{
    int n;
    cin >> n;
    f(1, n);
    return 0;
}