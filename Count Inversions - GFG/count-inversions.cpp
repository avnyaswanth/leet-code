// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long merge(long long arr[], long long l, long long p, long long h)
    {
        long long n = p-l+1;
        long long m = h-p;
        long long larr[n];
        long long rarr[m];
        for(long long i=0;i<n;++i)
            larr[i] = arr[l+i];
        for(long long i=0;i<m;++i)
            rarr[i] = arr[p+i+1];
        long long count = 0;
        long long i = 0, j = 0 ,k = l;
        while(i < n && j < m)
        {
            if(larr[i] <= rarr[j])
                arr[k++] = larr[i++];
            else
            {
                arr[k++] = rarr[j++];
                count += n-i;
            }
        }
        while(i<n)
            arr[k++] = larr[i++];
        while(j<m)
            arr[k++] = rarr[j++];
        return count;
    }
    long long mergeSort(long long arr[], long long l, long long h)
    {
        long long ans = 0;
        if(l < h)
        {
            long long p = l + (h-l)/2;
            ans += mergeSort(arr, l, p);
            ans += mergeSort(arr, p+1, h);
            ans += merge(arr, l, p, h);
        }
        return ans;
    }
    long long int inversionCount(long long arr[], long long n)
    {
        long long l = 0, h = n-1;
        return mergeSort(arr, l, h);
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends