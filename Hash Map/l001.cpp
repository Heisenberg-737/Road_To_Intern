#include <bits/stdc++.h>

using namespace std;

//Get Common Element ==============================================================================
void commonEle(vector<int> arr1, vector<int> arr2)
{
    unordered_map<int, int> mp;

    for (int val : arr1)
    {
        if (mp.find(val) != mp.end())
        {
            int of = mp[val];
            int nf = of + 1;
            mp[val] = nf;
        }
        else
        {
            mp[val] = 1;
        }
    }

    for (int val : arr2)
    {
        if (mp.find(val) != mp.end())
        {
            cout << val << endl;
            mp.erase(val);
        }
    }
}

//Get Common Element Intersection =================================================================
void commonEle2(vector<int> arr1, vector<int> arr2)
{
    unordered_map<int, int> mp;

    for (int val : arr1)
    {
        if (mp.find(val) != mp.end())
            mp[val]++;
        else
            mp[val] = 1;
    }

    for (int val : arr2)
    {
        if (mp.find(val) != mp.end())
        {
            if (mp[val] != 0)
            {
                cout << val << endl;
                mp[val]--;
            }
        }
    }
}

//Longest Consecutive Subsequence (LCS) ==========================================================

int lcsHash(vector<int> arr)
{
    unordered_map<int, bool> mp;

    for (int val : arr)
    {
        mp[val] = true;
    }

    for (int val : arr)
        if (mp.find(val - 1) != mp.end())
            mp[val] = false;

    int msp = 0; //max starting point
    int ml;      //max length

    for (int val : arr)
    {
        if (mp[val])
        {
            int tl = 1;
            int tsp = val;

            while (mp.find(tl + tsp) != mp.end())
                tl++;

            if (tl > ml)
            {
                msp = tsp;
                ml = tl;
            }
        }
    }

    return ml;
}

//================================================================================================
int main(int args, char **argv)
{
    vector<int> arr1 = {1, 1, 1, 2, 2, 2, 2, 3, 5}, arr2 = {1, 1, 1, 1, 1, 2, 2, 4, 4, 4, 5};
    // commonEle(arr1, arr2);
    // commonEle2(arr1, arr2);

    vector<int> arr = {4, 5, 8, 1, 3, 2, 4, 6, 9, 23};
    cout << lcsHash(arr) << endl;
}