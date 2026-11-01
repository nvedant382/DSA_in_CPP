#include <iostream>
using namespace std;

int main()
{
    int num = 7789, cnt = 0;
    while (num)
    {
        cnt += 1;
        num /= 10;
    }
    cout << cnt << endl;
    // T.C. = log10(N) due to division by 10

    int num2 = 7789, sum = 0, rev = 0;
    while (num2 > 0)
    {
        int lastDigit = num2 % 10;
        rev = rev * 10 + lastDigit;
        sum += lastDigit;
        num2 /= 10;
    }

    cout << rev << endl;
    cout << sum << endl;

    return 0;
}