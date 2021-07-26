// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
public:
    /*You are required to complete this method */
    int atoi(string str)
    {
        //Your code here
        int len = str.length();
        bool flag = false;

        if (str[0] == '-')
        {
            flag = true;
            str = str.substr(1, len);
            len--;
        }

        for (int i = 0; i < len; i++)
        {
            if (str[i] - 'a' >= 0 && str[i] - 'a' < 26)
                return -1;
        }

        int res = 0;
        for (int i = 0; i < len; i++)
        {
            int x = str[i] - '0';
            res = res * 10 + x;
        }

        return (flag == false) ? res : (res * -1);
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
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
} // } Driver Code Ends