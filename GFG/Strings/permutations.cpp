// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<string> find_permutation(string S)
    {
        // Code here there
        if (S.length() == 0)
        {
            vector<string> base;
            base.push_back("");
            return base;
        }

        char ch = S[0];
        vector<string> smallAns = find_permutation(S.substr(1));
        vector<string> BigAns(smallAns.size());
        for (string s : smallAns)
        {
            for (int i = 0; i <= s.length(); i++)
            {
                string str = s.substr(0, i) + ch + s.substr(i);
                if (str.length() == S.length())
                    BigAns.push_back(str);
            }
        }

        return BigAns;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends