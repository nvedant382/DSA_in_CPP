#include <iostream>
using namespace std;
// Rectangle
void printPattern(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ("*") << " ";
        }
        cout << "\n";
    }
}

/*

* * * *
* * * *
* * * *
* * * *

*/

// right angle triangle
void printPattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << ("*") << " ";
        }
        cout << "\n";
    }
}

/*
 *
 * *
 * * *
 * * * *
 */

// numbered right angle triangle (row)
void printPattern3(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

/*
1
1 2
1 2 3
1 2 3 4
*/

// numbered right angle triangle (column)
void printPattern4(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << i + 1 << " ";
        }
        cout << endl;
    }
}

/*
1
1 2
1 2 3
1 2 3 4
*/

// numbered right angle triangle (reverse)
void printPattern5_1(int n)
{
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "*" << " ";
        }
        cout << "\n";
    }
}

/*
 * * * *
 * * *
 * *
 *
 */

// right angle triangle (reverse)
void printPattern5_2(int n)
{
    // on each row we're doing row = row number + N - 1
    // cause 1th row -> 5 stars (1+5-1)
    //       2nd row -> 4 stars (2+5-1)
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << "*" << " ";
        }
        cout << endl;
    }
}

// numbered right angle triangle (reverse)
void printPattern6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            cout << j + 1 << " ";
        }
        cout << endl;
    }
}

/*
1 2 3 4
1 2 3
1 2
1
*/

// pyramid
void printPattern7_1(int n)
{
    // left-half
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // stars
        for (int k = 0; k <= i; k++)
        {
            cout << "*";
        }
        // right-half
        for (int j = 0; j < i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// pyramid
/*
              [space,stars,space]
0     *       [4,1,4]
1    ***      [3,3,3]
2   *****     [2,5,2]
3  *******    [1,7,1]
4 *********   [0,9,0]

3 for loops for 3 parameters

*/
void printPattern7_2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "-";
        }
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << "-";
        }
        cout << endl;
    }
}

// reverse pyramid
void printPattern8(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << "-";
        }
        for (int k = 0; k < (2 * n - (2 * i) - 1); k++)
        {
            cout << "*";
        }
        for (int l = 0; l < i; l++)
        {
            cout << "-";
        }
        cout << endl;
    }
}

/*
*******
-*****-
--***--
---*---
*/

/*
for diamond :->
printPattern7_2(n);
printPattern8(n);
*/

// horizontal mountain
void printPattern10_1(int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
 *
 **
 ***
 ****
 ***
 **
 *
 */

void printPattern10_2(int n)
{
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;

        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

// binary right angle triangle
void printPattern11(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
            start = 1;
        else
            start = 0;

        for (int j = 1; j <= i; j++)
        {
            cout << start;
            start = 1 - start;
        }
        cout << endl;
    }
}

/*
1
01
101
0101
*/

// numbered-stairecases
void printPattern12(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j;
        }
        for (int k = 1; k <= (2 * n - 2 * i); k++)
        {
            cout << " ";
        }
        for (int l = i; l >= 1; l--)
        {
            cout << l;
        }
        cout << endl;
    }
}

/*
1      1
12    21
123  321
12344321
*/

// numbered iterative right angled triangle
void printPattern13(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << num++ << " ";
        }
        cout << endl;
    }
}

/*
1
2 3
4 5 6
7 8 9 10
*/

// alphabet right angle triangle
void printPattern14(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j < 'A' + i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
A
A B
A B C
A B C D
*/

// alphabet right angled triangle (reverse)
void printPattern15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (char j = 'A'; j <= 'A' + (n - i); j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
A B C D
A B C
A B
A
*/

void printPattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j <= i; j++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
A
B B
C C C
D D D D
*/

// aplhabet pyramid
void printPattern17(int n)
{
    for (int i = 1; i <= n; i++)
    {
        // spaces
        for (int j = 1; j <= n - i; j++)
        {
            cout << "-";
        }
        // alphabets
        char ch = 'A';
        int breakpoint = (2 * i - 1) / 2; // symmetry line
        for (int j = 1; j <= (2 * i - 1); j++)
        {
            cout << ch;
            if (j <= breakpoint)
                ch++;
            else
                ch--;
        }
        // spaces
        for (int k = 1; k <= n - i; k++)
        {
            cout << "-";
        }
        cout << endl;
    }
}

/*
---A---
--ABA--
-ABCBA-
ABCDCBA
*/

// E-alphabet right angle triangle
void printPattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'E' - i; ch <= 'E'; ch++)
        {
            cout << ch << " ";
        }
        cout << endl;
    }
}

/*
E
D E
C D E
B C D E
*/

// hollow diamond
void printPattern19(int n)
{
    // first half
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 1; j <= n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int k = 1; k <= (2 * i); k++)
        {
            cout << " ";
        }
        // stars
        for (int l = 1; l <= n - i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // second half
    for (int i = 1; i <= n; i++)
    {
        // stars
        for (int j = 1; j <= i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int j = 1; j <= (2 * n - 2 * i); j++)
        {
            cout << " ";
        }
        // stars
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
********
***  ***
**    **
*      *
*      *
**    **
***  ***
********
*/

// butterfly
void printPattern20(int n)
{
    int spaces = (2 * n - 2);
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        int stars = i;
        if (i > n)
            stars = 2 * n - i;
        // stars
        for (int j = 1; j <= stars; j++)
        {
            cout << "*";
        }
        // spaces
        for (int k = 1; k <= spaces; k++)
        {
            cout << " ";
        }
        // stars
        for (int l = 1; l <= stars; l++)
        {
            cout << "*";
        }

        if (i < n)
            spaces -= 2;
        else
            spaces += 2;
        cout << endl;
    }
}

/*
 *      *
 **    **
 ***  ***
 ********
 ***  ***
 **    **
 *      *
 */

// hollow rectangle
void printPattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/*
****
*  *
*  *
****
*/

int main()
{
    int n;
    cin >> n;
    printPattern21(n);
    return 0;
}