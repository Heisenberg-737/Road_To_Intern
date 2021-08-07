// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to return Breadth First Traversal of given graph.
    vector<int> res;
    void bfs(int src, vector<int> adj[], vector<bool> &vis)
    {
        list<int> que;
        que.push_back(src);

        while (que.size() > 0)
        {
            int rem = que.front();
            que.pop_front();

            if (vis[rem])
            {
                continue;
            }

            vis[rem] = true;

            res.push_back(rem);

            for (int v : adj[rem])
            {
                if (!vis[v])
                {
                    que.push_back(v);
                }
            }
        }
    }

    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);

        bfs(0, adj, vis);
        return res;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
} // } Driver Code Ends