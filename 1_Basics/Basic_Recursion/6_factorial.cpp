#include <iostream>
using namespace std;
// TC and SC are O(N)
int fact(int n)
{
    if (n <= 1)
        return 1;
    return n * fact(n - 1);
}

int main()
{
    int n;
    cin >> n;
    cout << fact(n) << endl;
    return 0;
}