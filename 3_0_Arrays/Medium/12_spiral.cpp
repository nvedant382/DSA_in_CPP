#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    int left = 0, right = m - 1, top = 0, bottom = n - 1;

    while (left <= right && top <= bottom)
    {

        // right
        for (int i = left; i <= right; i++)
        {
            cout << mat[top][i] << " ";
        }
        top++;

        // bottom
        for (int i = top; i <= bottom; i++)
        {
            cout << mat[i][right] << " ";
        }
        right--;

        // check there exist a valid row
        if (top <= bottom)
        {

            // left
            for (int i = right; i >= left; i--)
            {
                cout << mat[bottom][i] << " ";
            }
            bottom--;
        }

        // check there exists a valid column to print
        while (left <= right)
        {

            // top
            for (int i = bottom; i >= top; i--)
            {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }
}

int main()
{
    vector<vector<int>> mat = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printSpiral(mat);
    return 0;
}