#include "../header.h"

const vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

bool isValidCell(int i, int j, const int nRow, const int nCol)
{
    return (i >= 0 && i < nRow && j >= 0 && j < nCol);
}

void dfs(vector<vector<char>> &A, int i, int j)
{
    int nRow = A.size();
    int nCol = A[0].size();
    if (!isValidCell(i, j, nRow, nCol))
    {
        return;
    }
    if (A[i][j] == 'X' || A[i][j] == 'B')
    {
        return;
    }
    A[i][j] = 'B';
    // cout << i << " " << j << endl;
    int u, v;

    for (const auto &d : directions)
    {
        u = i + d[0];
        v = j + d[1];
        dfs(A, u, v);
    }
}

void Solution::solve(vector<vector<char>> &A)
{
    int nRow = A.size();
    int nCol = A[0].size();
    if (nRow == 1 && nCol == 1)
    {
        return;
    }

    for (int i = 0; i < nRow; i++)
    {
        if (A[i][0] == 'O')
        {
            dfs(A, i, 0);
        }
        if (A[i][nCol - 1] == 'O')
        {
            dfs(A, i, nCol - 1);
        }
    }

    for (int j = 0; j < nCol; j++)
    {
        if (A[0][j] == 'O')
        {
            dfs(A, 0, j);
        }
        if (A[nRow - 1][j] == 'O')
        {
            dfs(A, nRow - 1, j);
        }
    }

    for (int i = 0; i < nRow; i++)
    {
        for (int j = 0; j < nCol; j++)
        {
            if (A[i][j] == 'B')
            {
                A[i][j] = 'O';
            }
            else
            {
                A[i][j] = 'X';
            }
        }
    }
}
