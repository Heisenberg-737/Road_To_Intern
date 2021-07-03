#include <bits/stdc++.h>

using namespace std;

int digit(int n)
{
    int count = 0;
    while (n != 0)
    {
        n /= 10;
        count++;
    }
    return count;
}

int rotate(int n, int r)
{
    r = r % digit(n);
    if (r < 0)
        r += digit(n);

    int mult = 1, div = 1;
    int d = digit(n);

    for (int i = 1; i <= d; i++)
    {
        if (i <= r)
            mult *= 10;
        else
            div *= 10;
    }

    int fdigits = n % div;
    int sdigits = n / div;

    return ((fdigits * mult) + sdigits);
}

int main(int args, char **argv)
{
    int n, r;
    cin >> n >> r;
    cout << "Rotated Number=" << rotate(n, r) << endl;
}