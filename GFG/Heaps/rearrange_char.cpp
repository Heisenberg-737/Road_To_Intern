#include <bits/stdc++.h>
using namespace std;

class Key
{
public:
    bool operator<(const Key &k) const
    {
        return freq < k.freq;
    }
    int freq;
    char ch;
};

int solve(string str)
{
    string ans = "";

    vector<int> mp(26, 0);
    priority_queue<Key> pq;

    for (int i = 0; i < str.length(); i++)
        mp[str[i] - 'a']++;

    for (char c = 'a'; c <= 'z'; c++)
    {
        if (mp[c - 'a'] > 0)
            pq.push({mp[c - 'a'], c});
    }

    Key prev{-1, '#'};

    while (pq.size() > 0)
    {
        Key root = pq.top();
        pq.pop();
        ans += root.ch;

        if (prev.freq > 0)
            pq.push(prev);

        root.freq--;
        prev = root;
    }

    if (str.length() != ans.length())
        return 0;
    else
        return 1;
}

int main()
{
    //code
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        cout << solve(str) << endl;
    }
    return 0;
}