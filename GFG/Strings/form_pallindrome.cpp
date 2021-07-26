// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int countMin(string str)
    {
        //complete the function here
        if (str.length() == 0 || str.length() == 1)
            return 0;

        if (str.length() == 2)
            return (str[0] == str[1]) ? 0 : 1;

        return (str[0] == str[str.length() - 1]) ? countMin(str.substr(1, str.length() - 1)) : (min(countMin(str.substr(0, str.length() - 1)), countMin(str.substr(1, str.length()))) + 1);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
    return 0;
}
