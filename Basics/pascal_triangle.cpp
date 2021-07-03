#include <bits/stdc++.h>

using namespace std;

void pascal(int rows)
{
    for (int n = 0; n <= rows; n++)
    {
        int val = 1;
        for (int r = 0; r <= n; r++)
        {
            cout << val << " ";
            val = (val * (n - r)) / (r + 1);
        }
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    pascal(n);
}