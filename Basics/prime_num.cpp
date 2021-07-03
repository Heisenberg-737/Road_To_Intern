#include <bits/stdc++.h>

using namespace std;

void prime(int n)
{
    bool p = true;

    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            p = false;
    }

    if (p == true)
        cout << "Its Prime" << endl;
    else
        cout << "Not a Prime" << endl;
}

int main(int args, char **agrv)
{
    int n;
    cin >> n;
    prime(n);
}