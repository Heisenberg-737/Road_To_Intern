// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int longestSubstrDitinctChars(string S);
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        cout << longestSubstrDitinctChars(S) << endl;
    }
}

int longestSubstrDitinctChars(string S)
{
    // your code here
    vector<int> map(26, -1);

    int i = 0, res = 0;

    for (int j = 0; j < S.length(); j++)
    {
        i = max(i, map[S[j] - 'a'] + 1);

        res = max(res, j - i + 1);

        map[S[j] - 'a'] = j;
    }

    return res;
}