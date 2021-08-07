// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the number of islands.
    void island(vector<vector<char>> &grid, int x, int y, vector<vector<bool>> &vis)
    {
        if (x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0' || vis[x][y])
        {
            return;
        }

        vis[x][y] = true;

        island(grid, x - 1, y, vis);
        island(grid, x, y - 1, vis);
        island(grid, x + 1, y, vis);
        island(grid, x, y + 1, vis);
        island(grid, x - 1, y - 1, vis);
        island(grid, x - 1, y + 1, vis);
        island(grid, x + 1, y - 1, vis);
        island(grid, x + 1, y + 1, vis);
    }

    int numIslands(vector<vector<char>> &grid)
    {
        // Code here
        vector<vector<bool>> vis(grid.size(), vector<bool>(grid[0].size(), false));

        int count = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == '1' && !vis[i][j])
                {
                    island(grid, i, j, vis);
                    count++;
                }
            }
        }

        return count;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
} // } Driver Code Ends