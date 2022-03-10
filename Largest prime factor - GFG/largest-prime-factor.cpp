// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

 // } Driver Code Ends
class Solution{
public: 
    bool isprime(int n)
    {
        if(n < 2)
            return false;
        for(int i=2;i<=sqrt(n);++i)
            if(n % i == 0)
                return false;
        return true;
    }
    long long int largestPrimeFactor(int N)
    {
        long long ans = 1;
        if(isprime(N))
            return N;
        for(int i=2;i<=sqrt(N);++i)
        {
            if(isprime(i))
            {
                while(N % i == 0)
                    N /= i;
                ans = i;
            }
        }
        if(N > 1)
            return N;
        return ans;
    }
};

// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.largestPrimeFactor(N) << endl;
    }
    return 0; 
}  // } Driver Code Ends