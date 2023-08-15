#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

void clear(vector<string> &grid, int row, int column);

int main()
{
    int casesCount, gridSize, result;
    vector<string> grid;

    scanf("%d", &casesCount);

    for (int caseId = 1; caseId <= casesCount; ++caseId)
    {
        scanf("%d", &gridSize);
        grid = vector<string>(gridSize);
        result = 0;
        for (int i = 0; i < gridSize; ++i)
        {
            cin >> grid[i];
        }

        for (int i = 0; i < gridSize; ++i)
        {
            for (int j = 0; j < gridSize; ++j)
            {
                if (grid[i][j] == 'x')
                {
                    ++result;
                    clear(grid, i, j);
                }
            }
        }

        printf("Case %d: %d\n", caseId, result);
    }

    return 0;
}

void clear(vector<string> &grid, int row, int column)
{
    if (row < 0 || row >= grid.size() || column < 0 || column >= grid[row].size() || grid[row][column] == '.')
    {
        return;
    }

    grid[row][column] = '.';
    clear(grid, row - 1, column);
    clear(grid, row + 1, column);
    clear(grid, row, column - 1);
    clear(grid, row, column + 1);
}