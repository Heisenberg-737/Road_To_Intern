// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    string remove(string s)
    {
        // code here
        if (s.length() == 1 || s.length() == 0)
        {
            return s;
        }

        if (s[0] == s[1])
        {
            while (s.length() > 1 && s[0] == s[1])
            {
                s = s.substr(1, s.length());
            }
            s = s.substr(1, s.length());

            return remove(s);
        }

        string rem = remove(s.substr(1, s.length()));

        if (rem.length() != 0 && rem[0] == s[0])
        {
            return rem.substr(1, rem.length());
        }

        if (rem.length() == 0)
        {
            return rem;
        }

        return (s[0] + rem);
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.remove(s) << "\n";
    }
    return 0;
}