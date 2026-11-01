#include <iostream>
#include <vector>
using namespace std;

void markRow(int i, vector<vector<int>> &arr)
{
    for (int j = 0; j < arr[0].size(); j++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

void markCol(int j, vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i][j] != 0)
        {
            arr[i][j] = -1;
        }
    }
}

void setZeros(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[0].size(); j++)
        {
            if (arr[i][j] == -1)
                arr[i][j] = 0;
        }
    }
}

void setMatToZero(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                markRow(i, arr);
                markCol(j, arr);
            }
        }
    }

    setZeros(arr);
}

void setMatToZeroBetter(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int row[n] = {0};
    int col[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                arr[i][j] = 0;
            }
        }
    }
}

void setMatToZeroBetterOptimal(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                // marking row
                arr[i][0] = 0;
                // marking col
                if (j != 0)
                    arr[0][i] = 0;
                else // for 1st column only
                    col0 = 0;
            }
        }
    }

    // mark every element except hash arrays
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                if (arr[0][j] == 0 || arr[i][0] == 0)
                {
                    arr[i][j] = 0;
                }
            }
        }
    }

    // mark column hash using [0][0]th ele
    if (arr[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            arr[0][j] = 0;
        }
    }

    // mark row hash using col0
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            arr[i][0] = 0;
        }
    }
}

int main()
{
    vector<vector<int>> arr = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    vector<vector<int>> arr2 = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};
    vector<vector<int>> arr3 = {{1, 1, 1, 1}, {1, 0, 0, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}};

    setMatToZero(arr);

    for (auto row : arr)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "---------";

    setMatToZeroBetter(arr2);

    for (auto row : arr2)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    cout << "---------";

    setMatToZeroBetterOptimal(arr3);

    for (auto row : arr3)
    {
        for (auto ele : row)
        {
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}