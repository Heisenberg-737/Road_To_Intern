#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int res = 0;
    int pow = 1;

    while (n != 0)
    {
        int c = n % 2;
        res = res + (pow * c);
        pow *= 10;
        n /= 2;
    }

    cout << res << endl;

    int ans = 0;
    int two = 1;

    while (res != 0)
    {
        int m = res % 10;
        ans = ans + (m * two);
        two *= 2;
        res /= 10;
    }

    cout << ans << endl;
}