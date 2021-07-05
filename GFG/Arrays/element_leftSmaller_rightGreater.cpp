// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int findElement(int arr[], int n);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) cin >> a[i];
        cout << findElement(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends


int findElement(int arr[], int n) {
    
    int leftarr[n];
    
    leftarr[0] = INT_MIN;
    
    for(int i=1;i<n;i++)
    {
        leftarr[i] = max(leftarr[i-1], arr[i-1]);
    }
    
    int rightMin = INT_MAX;
    
    for(int i=n-1;i>=0;i--)
    {
        if(leftarr[i] <= arr[i] && rightMin >= arr[i])
            return i;
            
        rightMin = min(rightMin, arr[i]);
    }
    
    return -1;
}