#include <bits/stdc++.h>

using namespace std;

int func(vector<int> &arr, int s)
{
    int res = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        vector<int> av(arr.size(), 0);

        av[i] = arr[i];

        if (arr[i] == s)
            res++;

        for (int j = i + 1; j < arr.size(); j++)
        {
            int avg = av[j - 1] + arr[j];
            av[j] = avg;

            if (((double)avg / (j - i + 1) == s))
            {
                res++;
            }
        }
    }

    return res;
}

// vector<int> func(vector<bool> &base2)
// {
//     int res = 0;
//     int pow = 1;
//     int i = 0;
//     while (i != base2.size())
//     {
//         int rem;
//         if (base2[i] == true)
//         {
//             rem = 1;
//         }
//         else
//         {
//             rem = 0;
//         }
//         res += rem * pow;
//         i++;
//         pow *= 2;
//     }

//     pow = 1;
//     vector<int> base6;

//     while (res != 0)
//     {
//         int c = res % 6;
//         base6.push_back(c);
//         res = res / 6;
//     }

//     return base6;
// }

//========================================

// int func(string wall, int k, char ch)
// {
//     int max_ = 1;
//     int cnt = 0;
//     int l = 0, r = 0;

//     while (r < wall.length())
//     {
//         if (wall[r] != ch)
//         {
//             ++cnt;
//         }

//         while (cnt > k)
//         {
//             if (wall[l] != ch)
//             {
//                 --cnt;
//             }

//             ++l;
//         }

//         max_ = max(max_, r - l + 1);
//         ++r;
//     }

//     return max_;
// }

// int FY22CampusPaintTheWall(string wall, int k)
// {
//     int max_ = 1;

//     for (int i = 0; i < 26; i++)
//     {
//         max_ = max(max_, func(wall, k, i + 'a'));
//     }

//     return max_;
// }

int main()
{
    // vector<bool> arr = {false, false, true, true};

    // vector<int> x = func(arr);
    // string wall = "abaab";
    // int k = 1;

    // int x = FY22CampusPaintTheWall(wall, k);
    // cout << x << endl;
}