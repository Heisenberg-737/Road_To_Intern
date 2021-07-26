// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    string longestPalin(string S)
    {
        // code here
        int start = 0, maxlength = 1;
        int len = S.length();

        for (int i = 1; i < len; i++)
        {
            int high = i;
            int low = i - 1;
            while (low >= 0 && high < len && S[low] == S[high])
            {
                if (high - low + 1 > maxlength)
                {
                    start = low;
                    maxlength = high - low + 1;
                }
                --low;
                ++high;
            }

            high = i + 1;
            low = i - 1;
            while (low >= 0 && high < len && S[low] == S[high])
            {
                if (high - low + 1 > maxlength)
                {
                    start = low;
                    maxlength = high - low + 1;
                }
                --low;
                ++high;
            }
        }

        for (int i = start; i <= start + maxlength - 1; i++)
            cout << S[i];
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
        cout << ob.longestPalin(S) << endl;
    }
}