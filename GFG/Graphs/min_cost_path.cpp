// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //Function to return the minimum cost to react at bottom
    //right cell from top left cell.
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    int minimumCostPath(vector<vector<int>> &grid)
    {
        // Code here
        vector<vector<int>> dis(grid.size(), vector<int>(grid.size(), INT_MAX));

        set<pair<int, pair<int, int>>> s;

        dis[0][0] = grid[0][0];

        s.insert({grid[0][0], {0, 0}});

        while (!s.empty())
        {
            auto it = s.begin();
            int x = (*it).second.first;
            int y = (*it).second.second;
            s.erase(it);

            for (int i = 0; i < 4; i++)
            {
                int x1 = x + dx[i];
                int y1 = y + dy[i];
                if (x1 >= 0 && y1 >= 0 && x1 < grid.size() && y1 < grid.size())
                {
                    if (dis[x1][y1] > dis[x][y] + grid[x1][y1])
                    {
                        if (dis[x1][y1] != INT_MAX)
                        {
                            s.erase({dis[x1][y1], {x1, y1}});
                        }

                        dis[x1][y1] = dis[x][y] + grid[x1][y1];
                        s.insert({dis[x1][y1], {x1, y1}});
                    }
                }
            }
        }

        // for(int i=0;i<dis.size();i++)
        // {
        //     for(int j=0;j<dis.size();j++)
        //     {
        //         cout<<dis[i][j]<<" ";
        //     }

        //     cout<<endl;
        // }

        return dis[grid.size() - 1][grid.size() - 1];
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n, -1));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.minimumCostPath(grid);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends