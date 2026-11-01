#include <iostream>
using namespace std;

bool isArmstrong(int num, int length)
{
    int ans = 0, temp = num;

    while (num > 0)
    {
        int multiple = 1; // reset to 1
        int lastDigit = num % 10;

        for (int i = 1; i <= length; i++)
        {
            multiple *= lastDigit;
        }

        ans += multiple;

        num /= 10;
    }

    if (temp == ans)
    {
        return true;
    }
    return false;
}

int findLength(int num)
{
    int cnt = 0;
    while (num > 0)
    {
        cnt += 1;
        num /= 10;
    }
    return cnt;
}

int main()
{
    int num;
    cin >> num;

    int len = findLength(num);

    if (isArmstrong(num, len))
    {
        cout << num << " is Armstrong number" << endl;
    }
    else
    {
        cout << num << " is not Armstrong number" << endl;
    }
    return 0;
}