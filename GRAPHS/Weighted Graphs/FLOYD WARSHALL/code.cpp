#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> shortest_distance(vector<vector<int>> &matrix)
{
    int n = matrix.size();//initializing the matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 1e9;
            }
            if (i == j)
                matrix[i][j] = 0;
        }
    }

    for (int k = 0; k < n; k++)//k is via node
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j],matrix[i][k] + matrix[k][j]);
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1e9)
            {
                matrix[i][j] = -1;
            }
        }
    }
return matrix;
}
