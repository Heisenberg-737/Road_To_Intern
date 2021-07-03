#include <bits/stdc++.h>

using namespace std;

void Dtob2(int n, int b2)
{
    int res = 0;
    int pow = 1;

    while (n != 0)
    {
        int c = n % b2;
        res += (c * pow);
        pow *= 10;
        n /= b2;
    }
}

void b1toD(int b1, int n, int b2)
{
    int res = 0;
    int pow = 1;

    while (n != 0)
    {
        int rem = n % 10;
        res += (rem * pow);
        pow *= b1;
        n /= 10;
    }

    Dtob2(res, b2);
}
int main()
{
    int b1, b2, n;
    cin >> b1 >> n >> b2;

    b1toD(b1, n, b2);
}