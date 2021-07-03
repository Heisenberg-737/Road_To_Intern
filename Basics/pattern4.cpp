#include <bits/stdc++.h>

using namespace std;

void pattern(int rows)
{
    int nst = 1;
    int nsp = rows * 2 - 2;

    for (int r = 1; r <= rows; r++)
    {
        for (int csp = 1; csp <= nsp / 2; csp++)
            cout << " ";
        for (int cst = 1; cst <= nst; cst++)
            cout << "*";
        for (int csp = 1; csp <= nsp / 2; csp++)
            cout << " ";
        cout << endl;
        if (r <= rows / 2)
        {
            nst += 2;
            nsp -= 2;
        }
        else
        {
            nst -= 2;
            nsp += 2;
        }
    }
}

int main()
{
    int rows;
    cin >> rows;

    pattern(rows);
}