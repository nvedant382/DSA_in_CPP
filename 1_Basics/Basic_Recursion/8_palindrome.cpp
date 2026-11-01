#include <iostream>
using namespace std;

bool is_palindrome(int i, string s, int n)
{
    if (i >= n / 2)
    {
        return true;
    }

    if (s[i] != s[n - i - 1])
    {
        return false;
    }

    return is_palindrome(i + 1, s, n);
}

int main()
{
    string s;
    cin >> s;

    int n = s.size();

    if (is_palindrome(0, s, n))
    {
        cout << "Yes,it is palindrome" << endl;
    }

    return 0;
}