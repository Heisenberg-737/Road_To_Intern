// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    //Function to find the minimum number of swaps required to sort the array.
    int minSwaps(vector<int> &nums)
    {
        // Code here
        pair<int, int> arr[nums.size()];
        for (int i = 0; i < nums.size(); i++)
        {
            arr[i].first = nums[i];
            arr[i].second = i;
        }

        sort(arr, arr + nums.size());

        vector<bool> vis(nums.size(), false);

        int ans = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (vis[i] || arr[i].second == i)
            {
                continue;
            }

            int cycles = 0;
            int j = i;

            while (!vis[j])
            {
                vis[j] = true;
                j = arr[j].second;

                cycles++;
            }

            if (cycles > 0)
            {
                ans += (cycles - 1);
            }
        }

        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution obj;
        int ans = obj.minSwaps(nums);
        cout << ans << "\n";
    }
    return 0;
} // } Driver Code Ends