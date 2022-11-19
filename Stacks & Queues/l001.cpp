#include <bits/stdc++.h>

using namespace std;

int distinctIds(vector<int> ids, int m)
{
    unordered_map<int, int> mp;
    vector<pair<int, int>> v;
    int count = 0;

    for (int i = 0; i < ids.size(); i++)
        mp[ids[i]]++;

    for (auto it : mp)
        v.push_back(make_pair(it.second, it.first));

    sort(v.begin(), v.end());

    int size = v.size();

    for (int i = 0; i < size; i++)
    {
        if (v[i].first <= m)
        {
            m -= v[i].first;
            count++;
        }

        else
            return size - count;
    }
    return size - count;
}

int countPairs(vector<int> numbers, int k)
{
    if (k != 0)
    {
        set<int> s;
        for (int i = 0; i < numbers.size(); i++)
        {
            s.insert(numbers[i]);
        }
        int ans = 0;
        for (auto it : s)
        {
            if (s.find(it + k) != s.end())
            {
                ans++;
            }
        }
        return ans;
    }
    else
    {
        unordered_map<int, int> m;
        for (int i = 0; i < numbers.size(); i++)
        {
            m[numbers[i]]++;
        }
        int ans = 0;
        for (auto it : m)
        {
            if (it.second >= 2)
            {
                ans++;
            }
        }
        return ans;
    }
}

int main()
{
    vector<int> v = {1, 2,3,4,5,6};
    int m = 2;

    cout << countPairs(v, m) << endl;
}