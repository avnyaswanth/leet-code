// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    int n = s.length();
	    int lps[n];
	    int i = 0, j = 1;
	    lps[0] = 0;
	    int maxLength = lps[0];
	    while(j < n)
	    {
	        if(s[i] == s[j])
            { 
               lps[j] = i+1;
               i++;
               j++;
            }
	        else
	        {
	            if(i != 0)
	                i = lps[i-1];
	            else
	            {
	                lps[j] = 0;
	                j++;
	            }
	        }
	    }
	    for(int i=0;i<n;++i)
	        maxLength = max(lps[j-1], maxLength);
	    return maxLength;
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends