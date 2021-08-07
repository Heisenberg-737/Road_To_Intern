#include <bits/stdc++.h>

using namespace std;

void solution(int n, vector<int> &r, vector<int> &c)
{
    vector<vector<char>> mine(n, vector<char>(n, '0'));
    for (int i = 0; i < r.size(); i++)
        mine[r[i]][c[i]] = 'B';

    int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mine[i][j] != 'B')
            {
                int count = 0;
                for (int k = 0; k < 8; k++)
                {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < n && y >= 0)
                    {
                        if(y < n && mine[x][y] == 'B')
                            count++;
                    }
                }
                mine[i][j] = '0' + count;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mine[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int n = 3;
    vector<int> r = {2, 1, 0, 2};
    vector<int> c = {0, 2, 1, 2};

    solution(n, r, c);
}