#include <bits/stdc++.h>

using namespace std;

void pattern(int rows)
{
    int nst = 1;
    int nsp = rows - 1;

    for (int r = 1; r <= rows; r++)
    {
        for (int csp = 1; csp <= nsp; csp++)
            cout << " ";
        for (int cst = 1; cst <= nst; cst++)
            cout << "*";
        cout << endl;
        nst++;
        nsp--;
    }
}

int main()
{
    int rows;
    cin >> rows;

    pattern(rows);
}