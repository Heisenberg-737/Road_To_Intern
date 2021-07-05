// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> arr, int n){
        
        int cost = 0, maxCost = 0;
        int start = 0, end = 0;
        vector<vector<int>> res(1, vector<int>(2,0));
        // code here
        
        int min_cost = arr[0];
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] < min_cost)
            {
                min_cost = arr[i];
                start = i;
            }
            
            cost = arr[i] - min_cost;
            
            if(cost > maxCost)
            {
                maxCost = cost;
                end = i;
            }
        }
        
        res[0][0] = start;
        res[0][1] = end;
        
        return res;
    }
};

// { Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}

  // } Driver Code Ends