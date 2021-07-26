// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution
{
public:
    string removeDups(string S)
    {
        // Your code goes here
        vector<int> map(26, 0);

        string res = "";

        for (int i = 0; i < S.length(); i++)
        {
            if (map[S[i] - 'a'] == 0)
            {
                res = res + S[i];
                map[S[i] - 'a']++;
            }
        }

        return res;
    }
};

// { Driver Code Starts.

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}