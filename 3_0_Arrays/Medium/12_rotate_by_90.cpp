#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> RotateBy90(vector<vector<int>> &mat)
{
    vector<vector<int>> ans(3, vector<int>(3, 0));
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            ans[j][n - 1 - i] = mat[i][j];
        }
    }

    return ans;
}

void optimal(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            swap(mat[i][j], mat[j][i]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        reverse(mat[i].begin(), mat[i].end());
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    vector<vector<int>> ans = RotateBy90(mat);
    for (auto row : ans)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "-------------" << endl;
    optimal(mat);
    for (auto row : mat)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}