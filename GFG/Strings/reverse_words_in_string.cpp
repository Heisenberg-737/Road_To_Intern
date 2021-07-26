// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to reverse words in a given string.
    string reverseWords(string S)
    {
        // code here
        vector<string> arr;
        string str = "";

        for (int i = 0; i < S.length(); i++)
        {
            if (S[i] == '.')
            {
                arr.push_back(".");
                arr.push_back(str);
                str = "";
            }

            else
                str += S[i];
        }

        arr.push_back(".");
        arr.push_back(str);
        str = "";

        for (int i = arr.size() - 1; i > 0; i--)
            str += arr[i];

        return str;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
} // } Driver Code Ends