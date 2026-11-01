#include <iostream>
#include <vector>
using namespace std;

int nCr(int n, int r)
{
    int res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void PascalRow(int n)
{
    for (int c = 1; c <= n; c++)
    {
        cout << nCr(n - 1, c - 1) << " ";
    }
}

void PascalRow_opt(int n)
{
    int ans = 1;
    cout << ans << " ";

    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
}

vector<int> generateRow(int row)
{
    vector<int> ansRow;
    long long ans = 1;
    ansRow.push_back(ans);

    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }

    return ansRow;
}

vector<vector<int>> pascal_triangle(int numRows)
{
    vector<vector<int>> ans;

    for (int i = 1; i <= numRows; i++)
    {
        ans.push_back(generateRow(i));
    }

    return ans;
}

int main()
{
    cout << nCr(5, 2) << endl;
    PascalRow(5);
    cout << endl;
    PascalRow_opt(5);

    vector<vector<int>> ans = pascal_triangle(5);
    for (auto row : ans)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    return 0;
}