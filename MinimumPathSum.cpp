#include <iostream>
#include <vector>

using namespace std;

int MinimumPathSums(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m, n;
        vector<vector<int>> grid(m, vector<int>(m, -1));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        cout << MinimumPathSum(grid);
        cout << endl;
    }
    return 0;
}