// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in a directed graph.
    bool dfs(int src, vector<int> adj[], vector<bool> &vis, vector<bool> &recStack)
    {
        if (!vis[src])
        {
            vis[src] = true;
            recStack[src] = true;

            for (int v : adj[src])
            {
                if (!vis[v] && dfs(v, adj, vis, recStack))
                    return true;
                else if (recStack[v])
                    return true;
            }
        }

        recStack[src] = false;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<bool> vis(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                bool res = dfs(i, adj, vis, recStack);
                if (res == true)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

// { Driver Code Starts.

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends