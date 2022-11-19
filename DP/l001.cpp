#include <bits/stdc++.h>

using namespace std;

//Fibonnaci:DP O(n) =================================================================================================================
int fibbomemo(int n, vector<int> &qb)
{
    if (n == 1 or n == 0)
        return n;

    if (qb[n] != 0)
        return qb[n];

    int fib1 = fibbomemo(n - 1, qb);
    int fib2 = fibbomemo(n - 2, qb);

    int fib = fib1 + fib2;
    qb[n] = fib;

    return fib;
}

//Fibonnaci:DP O(log n) ===========================================================================================================
void multiply(vector<vector<int>> &F, vector<vector<int>> &M)
{
    int w = F[0][0] * M[0][0] + F[0][1] * M[1][0];
    int x = F[0][0] * M[0][1] + F[0][1] * M[1][1];
    int y = F[1][0] * M[0][0] + F[1][1] * M[1][0];
    int z = F[1][0] * M[0][1] + F[1][1] * M[1][1];

    F[0][0] = w;
    F[0][1] = x;
    F[1][0] = y;
    F[1][1] = z;
}

void power(vector<vector<int>> &M, int n)
{
    if (n <= 1)
        return;

    vector<vector<int>> F = {{1, 1}, {1, 0}};

    power(M, n / 2);
    multiply(M, M); // a^b = a^(b/2)*a^(b/2) == for even

    if ((n & 1) != 0)
        multiply(M, F); //a^(b+1) = a^(b/2)*a^(b/2)*a == for odd
}

int fibbo(int n)
{
    if (n == 0)
        return 0;

    vector<vector<int>> M = {{1, 1}, {1, 0}};

    power(M, n);

    return M[0][1];
}

//Stair Climb Count No of Steps:DP (Memo) ==========================================================================================
int countStepsMemo(int n, vector<int> &q) //Memoisation
{
    if (n == 0)
        return 1;
    else if (n < 0)
        return 0;

    if (q[n] != 0)
    {
        return q[n];
    }

    int cnt = countStepsMemo(n - 1, q) + countStepsMemo(n - 2, q) + countStepsMemo(n - 3, q);

    q[n] = cnt;

    return cnt;
}

int countStepsTab(int n) // Tabulation
{
    vector<int> dp(n + 1);
    dp[0] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
            dp[i] = dp[i - 1];
        else if (i == 2)
            dp[i] = dp[i - 1] + dp[i - 2];
        else
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
    }

    return dp[n];
}

//Climbing Stair Variable Steps from Base(ie, 0) ===========
int varcountStepsTab(int n, vector<int> &arr)
{
    vector<int> dp(n + 1);
    dp[n] = 1; //to reach target stair, we need 1 move. Hence, smaller problem lies towards nth index

    for (int i = n - 1; i >= 0; i--) //direction is in reverse direction, as bigger problem lies towards 0th index
    {
        for (int j = 1; j <= arr[i] && i + j < dp.size(); j++)
        {
            dp[i] += dp[i + j];
        }
    }

    return dp[0]; // We move towards smaller to bigger problem waala index, so return 0th index
}

//Climbing Stairs with Minimum Moves==========================
int minMovesStepsTab(int n, vector<int> &arr)
{
    vector<int> dp(n + 1);
    dp[n] = 0; //Min Moves to reach Nth step is zero

    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > 0)
        {
            // cout << arr[i] << endl;
            int min_ = INT32_MAX;

            for (int j = 1; j <= arr[i] && i + j < dp.size(); j++)
            {
                if (dp[i + j] >= 0)
                    min_ = min(min_, dp[i + j]);
            }

            if (min_ != INT32_MAX)
                dp[i] = min_ + 1;
        }
    }

    // for (int ele : dp)
    // {
    //     cout << ele << " ";
    // }
    // cout << endl;

    return dp[0];
}

//Min Cost Maze Traversal ====================================================================================================

int minCostMaze(vector<vector<int>> &maze)
{
    int n = maze.size();
    int m = maze[0].size();

    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            if (i == n - 1 && j == m - 1)
            {
                dp[i][j] = maze[i][j];
            }
            else if (i == n - 1)
            {
                dp[i][j] = dp[i][j + 1] + maze[i][j];
            }
            else if (j == m - 1)
            {
                dp[i][j] = dp[i + 1][j] + maze[i][j];
            }
            else
            {
                dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]) + maze[i][j];
            }
        }
    }

    return dp[0][0];
}

//Gold Mine Highest Collect ==================================================================================================
int goldmine(vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();
    vector<vector<int>> dp(n, vector<int>(m));

    for (int j = m - 1; j >= 0; j--)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (j == m - 1)
            {
                dp[i][j] = arr[i][j];
            }
            else if (i == 0)
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i + 1][j + 1]);
            }
            else if (i == n - 1)
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], dp[i - 1][j + 1]);
            }
            else
            {
                dp[i][j] = arr[i][j] + max(dp[i][j + 1], max(dp[i - 1][j + 1], dp[i + 1][j + 1]));
            }
        }
    }

    int max_ = dp[0][0];

    for (int i = 0; i < n; i++)
    {
        max_ = max(max_, dp[i][0]);
    }

    return max_;
}

//Target Sum Subset ==========================================================================================================

bool tarSumSubset(vector<int> &arr, int tar)
{
    vector<vector<bool>> dp(arr.size() + 1, vector<bool>(tar + 1));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = true;
            else if (i == 0)
                dp[i][j] = false;
            else if (j == 0)
                dp[i][j] = true;
            else
            {
                if (dp[i - 1][j])
                {
                    dp[i][j] = true;
                }
                else
                {
                    int val = arr[i - 1];
                    if (j >= val)
                    {
                        if (dp[i - 1][j - val])
                        {
                            dp[i][j] = true;
                        }
                    }
                }
            }
        }
    }

    return dp[arr.size()][tar];
}

//Coin Change Combination Problem ============================================================================================
//we need to find the combinations of numbers which sum up to a certain target where each number can be used repetitively ====

int coinChangeCombi(vector<int> &arr, int tar)
{
    vector<int> dp(tar + 1);
    dp[0] = 1;

    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = arr[i]; j < dp.size(); j++)
        {
            dp[j] += dp[j - arr[i]];
        }
    }

    return dp[tar];
}

//Coin Change Permutation Problem ============================================================================================
//we need to find the permutations of numbers which sum up to a certain target where each number can be used repetitively ====

int coinChangePermu(vector<int> &arr, int tar)
{
    vector<int> dp(tar + 1);
    dp[0] = 1;

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[j] <= i)
                dp[i] += dp[i - arr[j]];
        }
    }

    return dp[tar];
}

//0-1 Knapsack Problem =======================================================================================================
//we are required to fill a knapsack with weights up to certain capacity which have the greatest value =======================
//Note - Each item can be taken 0 or 1 number of times. You are not allowed to put the same item again and again. ============

int knapsack(int n, vector<int> &vals, vector<int> &w, int cap)
{
    vector<vector<int>> dp(n + 1, vector<int>(cap + 1, 0));

    for (int i = 1; i < dp.size(); i++)
    {
        for (int j = 1; j < dp[0].size(); j++)
        {
            if (j >= w[i - 1])
            {
                if (dp[i - 1][j - w[i - 1]] + vals[i - 1] > dp[i - 1][j])
                {
                    dp[i][j] = dp[i - 1][j - w[i - 1]] + vals[i - 1];
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][cap];
}

//Unbounded Knapsack Problem =================================================================================================================
//we are required to fill a knapsack such that the maximum value is obtained from the weights put into the sack without exceeding its capacity
//Note - Each item can be taken any number of times. You are allowed to put the same item again and again ====================================

int unboundedKnapsack(int n, vector<int> &vals, vector<int> &w, int cap)
{
    vector<int> dp(cap + 1);

    dp[0] = 0;

    for (int i = 1; i <= cap; i++)
    {
        int max_ = 0;
        for (int j = 0; j < n; j++)
        {
            if (w[j] <= i)
            {
                int rembagc = i - w[j];
                int totalbagv = dp[rembagc] + vals[j];

                if (totalbagv > max_)
                    max_ = totalbagv;
            }
        }

        dp[i] = max_;
    }

    return dp[cap];
}

//Count Binary Strings with no consecutive 0 of length n =====================================================================

int countBinaryStrings(int n)
{
    vector<int> dp0(n + 1, 0);
    vector<int> dp1(n + 1, 0);

    dp1[1] = 1;
    dp0[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp1[i] = dp0[i - 1] + dp1[i - 1];
        dp0[i] = dp1[i - 1];
    }

    return dp0[n] + dp1[n];
}

//Longest Increasing Subsequence (LIS) =======================================================================================

int lis(vector<int> &arr, int n)
{
    int omax = 0;
    vector<int> dp(n);

    for (int i = 0; i < dp.size(); i++)
    {
        int max_ = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                if (dp[j] > max_)
                {
                    max_ = dp[j];
                }
            }
        }

        dp[i] = max_ + 1;

        if (dp[i] > omax)
        {
            omax = dp[i];
        }
    }

    return omax;
}

//Maximum Sum Increasing =====================================================================================================

int maxSumIncreasing(int n, vector<int> &arr)
{
    vector<int> dp(n);
    int omax = INT32_MIN;

    for (int i = 0; i < dp.size(); i++)
    {
        int max_ = -1;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] <= arr[i])
            {
                if (max_ == -1)
                    max_ = dp[j];
                else if (dp[j] > max_)
                    max_ = dp[j];
            }
        }

        if (max_ == -1)
            dp[i] = arr[i];
        else
            dp[i] = max_ + arr[i];

        if (dp[i] > omax)
            omax = dp[i];
    }

    return omax;
}

//Longest Bitonic Subsequence ================================================================================================
//Bitonic subsequences begin with elements in increasing order, followed by elements in decreasing order =====================
int longbitonicsubseq(int n, vector<int> &arr)
{
    vector<int> lis(n, 0); //longest increasing subseq
    for (int i = 0; i < n; i++)
    {
        int max_ = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] <= arr[i])
            {
                if (lis[j] > max_)
                {
                    max_ = lis[j];
                }
            }
        }

        lis[i] = max_ + 1;
    }

    vector<int> lds(n, 0); //longest decreasing subseq
    for (int i = n - 1; i >= 0; i--)
    {
        int max_ = 0;

        for (int j = n - 1; j > i; j--)
        {
            if (arr[j] <= arr[i])
            {
                if (lds[j] > max_)
                {
                    max_ = lds[j];
                }
            }
        }

        lds[i] = max_ + 1;
    }

    int omax = 0;

    for (int i = 0; i < n; i++)
    {
        if (lis[i] + lds[i] - 1 > omax)
            omax = lis[i] + lds[i] - 1;
    }

    return omax;
}

//Longest Common Subsequence (LCS) ===========================================================================================

int lcs(string str1, string str2)
{
    vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1, 0));

    for (int i = dp.size() - 2; i >= 0; i--)
    {
        for (int j = dp[0].size() - 2; j >= 0; j--)
        {
            if (str1[i] == str2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }

    return dp[0][0];
}

//Edit Distance ==============================================================================================================

int editDistance(string str1, string str2)
{
    vector<vector<int>> dp(str1.length() + 1, vector<int>(str2.length() + 1, 0));

    for (int i = 0; i < dp.size(); i++)
    {
        for (int j = 0; j < dp[0].size(); j++)
        {
            if (i == 0)
                dp[i][j] = j;
            else if (j == 0)
                dp[i][j] = i;
            else
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                {
                    int f1 = dp[i][j - 1];     //insertion
                    int f2 = dp[i - 1][j - 1]; //replace
                    int f3 = dp[i - 1][j];     //deletion

                    dp[i][j] = min(f1, min(f2, f3)) + 1;
                }
            }
        }
    }

    return dp[dp.size() - 1][dp[0].size() - 1];
}

//============================================================================================================================

int main(int args, char **argv)
{
    // int n = 10;
    // vector<int> qb(n + 1, 0);
    // int f = fibbo(n, qb);
    // int f = fibbo(n);
    // cout << f << endl;
    // cout << countStepsMemo(n, qb) << endl;
    // cout << countStepsTab(n) << endl;

    // vector<int> var = {3, 3, 0, 2, 2, 3};
    // cout << varcountStepsTab(n, var) << endl;

    // vector<int> arr = {1,1,1,4,9,8,1,1,10,1};
    // cout << minMovesStepsTab(n, arr) << endl;

    // vector<vector<int>> arr = {{1, 2, 7}, {3, 0, 9}, {9, 8, 2}};
    // cout << minCostMaze(arr) << endl;

    // vector<vector<int>> gold = {{3, 2, 2}, {9, 2, 4}, {8, 5, 1}};
    // cout << goldmine(gold) << endl;

    // vector<int> arr = {4, 2, 3, 1, 7};
    // int target = 10;
    // cout << tarSumSubset(arr, target) << endl;

    // vector<int> arr = {2, 3, 5};
    // int tar = 7;
    // cout << coinChangeCombi(arr, tar) << endl;

    // vector<int> arr = {2, 3, 5};
    // int tar = 7;
    // cout << coinChangePermu(arr, tar) << endl;

    // int n = 5;
    // vector<int> v = {15, 14, 10, 45, 30};
    // vector<int> weight = {2, 5, 1, 3, 4};
    // int capWeight = 7;
    // cout << knapsack(n, v, weight, capWeight) << endl;

    // int n = 5;
    // vector<int> v = {15, 14, 10, 45, 30};
    // vector<int> weight = {2, 5, 1, 3, 4};
    // int capWeight = 7;
    // cout << unboundedKnapsack(n, v, weight, capWeight) << endl;

    // cout << lcs("abcd", "aebd") << endl;
    cout << lcs("abcdgh", "acdghr") << endl;

    // cout << editDistance("ahellobye", "amezooe") << endl;
}