// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool allocatepages(int arr[], int n, int atmax, int k)
    {
        long pages = 0, studs = 1;
        for(int i=0;i<n;++i)
        {
            if(arr[i] > atmax)
                return 0;
            if(pages + arr[i] > atmax)
            {
                studs++;
                pages = arr[i];
            }
            else pages += arr[i];
        }
        if(studs > k)
            return 0;
        return 1;
    }
    
    int findPages(int arr[], int n, int k) 
    {
        sort(arr, arr+n);
        int ans = -1;
        if(k > n)
            return -1;
        long total = 0;
        for(int i=0;i<n;++i)
            total += arr[i];
            
        long low = arr[0], high = total;
        while(low <= high)
        {
            long mid = low + (high - low) / 2;
            if(allocatepages(arr, n, mid, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends