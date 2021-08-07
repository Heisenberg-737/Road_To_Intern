// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

#define M 26
class Solution
{
public:
    void dfs(vector<int> gr[], vector<bool> &vis, int src)
    {
        vis[src] = true;

        for (int i = 0; i < gr[src].size(); i++)
        {
            if (!vis[gr[src][i]])
            {
                dfs(gr, vis, gr[src][i]);
            }
        }
    }

    int isCyclic(vector<int> gr[], vector<bool> &mark, int src)
    {
        vector<bool> vis(M, false);

        dfs(gr, vis, src);

        for (int i = 0; i < M; i++)
        {
            if (mark[i] && !vis[i])
            {
                return 0;
            }
        }

        return 1;
    }

    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<bool> mark(M, false);

        vector<int> gr[M];

        vector<int> in(M, 0), out(M, 0);

        for (int i = 0; i < N; i++)
        {
            int f = A[i].front() - 'a';
            int l = A[i].back() - 'a';

            mark[f] = true;
            mark[l] = true;

            in[l]++;
            out[f]++;

            gr[f].push_back(l);
        }

        for (int i = 0; i < M; i++)
        {
            if (in[i] != out[i])
            {
                return 0;
            }
        }

        return isCyclic(gr, mark, A[0].front() - 'a');
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++)
        {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(N, A) << endl;
    }
    return 0;
} // } Driver Code Ends