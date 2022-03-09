// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  {
	    int target = 0;
	    for(int i=0;i<n;++i)
	        target += arr[i];
	    int r = target;
	    target = target / 2;
	    int dp[n+1][target+1];
        
        for(int i=0;i<n+1;++i)
        {
            for(int j=0;j<target+1;++j)
            {
                if(i == 0)
                    dp[i][j] = 0;
                if(j == 0)
                    dp[i][j] = 1;
            }
        }
        
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=target;++j)
            {
                if(arr[i-1] <= j)
                {
                    dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i-1][j];
                }
                else dp[i][j] = dp[i-1][j];
            }
        }
        int res = INT_MAX;
        for(int i=0;i<=target;++i)
        {
            if(dp[n][i] == 1)
                res = min(res, r-2*i);
        }
        return res;
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends