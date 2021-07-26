#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {

        // Your code here
        vector<int> map1(26, 0);
        vector<int> map2(26, 0);

        for (int i = 0; i < a.length(); i++)
        {
            map1[a[i] - 'a']++;
        }

        for (int i = 0; i < b.length(); i++)
        {
            map2[b[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++)
        {
            if (map1[i] != map2[i])
                return false;
        }

        return true;
    }
};

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}