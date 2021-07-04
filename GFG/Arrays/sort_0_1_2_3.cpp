//Initial Template for C

#include <stdio.h>


 // } Driver Code Ends
//User function Template for C

void sort012(int a[], int n)
{
    int cnt0 = 0, cnt1 = 0, cnt2 =0, i=0;
    
    for(i =0; i< n; i++)
    {
        if(a[i] == 0)
        {
            cnt0++;
            continue;
        }
        else if(a[i] == 1)
        {
            cnt1++;
            continue;
        }
        else
        {
            cnt2++;
            continue;
        }
        
    }
    
    i = 0;
    
    while(cnt0 != 0)
    {
        a[i++] = 0;
        cnt0--;
    }
    
    while(cnt1 != 0)
    {
        a[i++] = 1;
        cnt1--;
    }
    
    while(cnt2 != 0)
    {
        a[i++] = 2;
        cnt2--;
    }
}

// { Driver Code Starts.

int main() {

    int t;
    scanf("%d", &t);

    while(t--){
        int n;
        scanf("%d", &n);
        int arr[n];
        for(int i=0;i<n;i++){
            scanf("%d", &arr[i]);
        }

        sort012(arr, n);

        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends