// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find number of strongly connected components in the graph.
    int count = 0;
    void dfs(int v, vector<bool> &vis, vector<int> adj[])
    {
        vis[v] = true;
        cout << v << " ";

        for (int nbr : adj[v])
        {
            if (!vis[nbr])
            {
                dfs(nbr, vis, adj);
            }
        }
    }

    void topo_sort(int src, vector<int> adj[], vector<bool> &vis, stack<int> &st)
    {
        vis[src] = true;

        for (int nbr : adj[src])
        {
            if (!vis[nbr])
            {
                topo_sort(nbr, adj, vis, st);
            }
        }

        st.push(src);
    }

    void inverse(vector<int> adj[], vector<int> gr[], int V)
    {
        for (int v = 0; v < V; v++)
        {
            for (auto i = adj[v].begin(); i != adj[v].end(); i++)
            {
                gr[*i].push_back(v);
            }
        }
    }

    int kosaraju(int V, vector<int> adj[])
    {
        //code here
        stack<int> st;
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++)
        {
            topo_sort(i, adj, vis, st);
        }
        vector<int> gr[V];

        inverse(adj, gr, V);
        vector<bool> vis1(V, false);

        while (st.size() > 0)
        {
            int rem = st.top();
            st.pop();

            if (!vis1[rem])
            {
                dfs(rem, vis1, gr);
                cout << endl;
                count++;
            }
        }

        return count;
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
        cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends