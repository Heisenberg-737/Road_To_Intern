#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> ppi;

//Kth Largest Element =========================================================

void kthLargest(vector<int> arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);

        if (k < pq.size())
            pq.pop();
    }

    cout << pq.top() << endl;
}

//Sort K-sorted ================================================================

void ksorted(vector<int> arr, int k)
{
    int n = arr.size();
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i <= k; i++)
        pq.push(arr[i]);

    for (int i = k + 1; i < n; i++)
    {
        cout << pq.top() << endl;
        pq.pop();
        pq.push(arr[i]);
    }

    while (pq.size() > 0)
    {
        cout << pq.top() << endl;
        pq.pop();
    }
}

//Median Priority Queue ========================================================

void medianPQ(vector<int> arr, int n)
{
    priority_queue<int> sml;                            //smaller half - max heap
    priority_queue<int, vector<int>, greater<int>> lar; //larger half

    int med = arr[0];
    sml.push(arr[0]);

    for (int i = 1; i < n; i++)
    {
        int x = arr[i];

        //Case - 1: left side heap has more ele
        if (sml.size() > lar.size())
        {
            if (x < med)
            {
                lar.push(sml.top());
                sml.pop();
                sml.push(x);
            }
            else
                lar.push(x);

            med = (sml.top() < lar.top()) ? sml.top() : lar.top();
        }

        //Case - 2: Both Heaps are balanced
        else if (sml.size() == lar.size())
        {
            if (x < med)
            {
                sml.push(x);
                med = sml.top();
            }
            else
            {
                lar.push(x);
                med = lar.top();
            }
        }

        //Case - 3: Right side heap has more elements
        else
        {
            if (x > med)
            {
                sml.push(lar.top());
                lar.pop();
                lar.push(x);
            }
            else
                sml.push(x);

            med = (sml.top() < lar.top()) ? sml.top() : lar.top();
        }
    }

    cout << med << endl;
}

//Merge K Sorted Arrays ========================================================

void mergeKArrays(vector<vector<int>> arr)
{
    vector<int> output;

    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;

    for (int i = 0; i < arr.size(); i++)
        pq.push({arr[i][0], {i, 0}}); //val, array no, starting index

    while (pq.size() > 0)
    {
        ppi curr = pq.top();
        pq.pop();

        int i = curr.second.first; //array no
        int j = curr.second.second; //current index

        output.push_back(curr.first); //pushing val into array

        if (j + 1 < arr[i].size())
            pq.push({arr[i][j + 1], {i, j + 1}});
    }

    for (int ele : output)
        cout << ele << endl;
}

//==============================================================================

int main(int args, char **argv)
{

    // kthLargest({3, 2, 5, 7, 8, 6, 9, 1}, 4);
    // ksorted({2, 3, 1, 4, 6, 7, 5, 8, 9}, 2);
    // medianPQ({10, 20, 40, 50, 60}, 5);

    vector<vector<int>> arr = {{1, 3},
                               {2, 4, 6},
                               {0, 9, 10, 11}};

    mergeKArrays(arr);
    return 0;
}