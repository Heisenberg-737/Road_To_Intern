#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if (str1.length() != str2.length())
        {
            return false;
        }

        if (str1.length() < 2)
        {
            return str1.compare(str2) == 0;
        }

        string clockwise = "";
        string antiwise = "";
        int len = str1.length();

        clockwise = clockwise + str2.substr(2) + str2.substr(0, 2);
        antiwise = antiwise + str2.substr(len - 2, len) + str2.substr(0, len - 2);

        return (str1.compare(clockwise) == 0 || str1.compare(antiwise) == 0);
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
        string b;
        cin >> s >> b;
        Solution obj;
        cout << obj.isRotated(s, b) << endl;
    }
    return 0;
}