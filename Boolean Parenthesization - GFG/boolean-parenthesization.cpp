// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unordered_map<string, int> mp;
    
    int countways(string s, int n, int i, int j, bool istrue)
    {
        if(i > j)
            return 0;
            
        if(i == j)
        {
            if(istrue == true)
                return s[i] == 'T';
            else return s[i] == 'F';
        }
        
        string key = to_string(i);
        key += " " + to_string(j) + " " + to_string(istrue);
        if(mp.find(key) != mp.end())
            return mp[key];
        
        int ans = 0;
        
        for(int k=i+1;k<=j-1;k += 2)
        {
            int lt = countways(s, n, i, k-1, true);
            int lf = countways(s, n, i, k-1, false);
            int rt = countways(s, n, k+1, j, true);
            int rf = countways(s, n, k+1, j, false);
            
            if(s[k] == '&')
            {
                if(istrue == true)
                    ans += lt * rt;
                else ans += lt * rf + lf * rt + lf * rf;
            }
            
            else if(s[k] == '|')
            {
                if(istrue == true)
                    ans += lt * rf + lf * rt + lt * rt;
                else ans += lf * rf;
            }
            
            else
            {
                if(istrue == true)
                    ans += lt * rf + lf * rt;
                else ans += lf * rf + lt * rt;
            }
        }
        
        return mp[key] = ans % 1003;
    }
    
    int countWays(int N, string S){
        // code here
        mp.clear();
        return countways(S, N, 0,N-1,true);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        string S;
        cin>>S;
        
        Solution ob;
        cout<<ob.countWays(N, S)<<"\n";
    }
    return 0;
}  // } Driver Code Ends