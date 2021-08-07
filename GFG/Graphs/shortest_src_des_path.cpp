// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    int count = INT_MAX;
    void allPath(int n, int m, int a, int b, int x, int y, vector<vector<int>> arr, int steps)
    {

        if (a < 0 || b < 0 || a >= m || b >= n)
        {
            return;
        }

        if (arr[a][b] == 0 || arr[a][b] == INT_MAX)
        {
            return;
        }

        if (a == x && b == y)
        {
            count = min(count, steps);
            return;
        }

        arr[a][b] = INT_MAX;

        allPath(n, m, a + 1, b, x, y, arr, steps + 1);
        allPath(n, m, a, b + 1, x, y, arr, steps + 1);
        allPath(n, m, a - 1, b, x, y, arr, steps + 1);
        allPath(n, m, a, b - 1, x, y, arr, steps + 1);
    }

    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y)
    {
        // code here

        if (A[X][Y] == 0 || A[0][0] == 0)
            return -1;

        allPath(N, M, 0, 0, X, Y, A, 0);

        if (count < INT_MAX)
            return count;

        return -1;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
} // } Driver Code Ends