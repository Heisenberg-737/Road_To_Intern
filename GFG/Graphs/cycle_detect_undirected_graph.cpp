// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to detect cycle in an undirected graph.
    bool bfs(int src, vector<int> adj[], vector<bool> vis)
    {
        list<int> que;
        que.push_back(src);

        while (que.size() > 0)
        {
            int rem = que.front();
            que.pop_front();

            if (vis[rem])
            {
                return true;
            }

            vis[rem] = true;

            for (int v : adj[rem])
            {
                if (!vis[v])
                {
                    que.push_back(v);
                }
            }
        }

        return false;
    }

    bool isCycle(int V, vector<int> adj[])
    {
        // Code here
        vector<bool> vis(V, false);
        for (int i = 0; i < V; i++)
        {
            bool flag = bfs(i, adj, vis);

            if (flag)
            {
                return true;
            }
        }

        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
} // } Driver Code Ends