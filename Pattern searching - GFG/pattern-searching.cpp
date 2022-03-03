// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

/*
str: string in which pattern we have to find pattern.
text: pattern needs to searched.
*/

void computeLps(int *lps, int m, string pat)
{
    lps[0] = 0;
    int i = 1;
    int j;
    for(int i=1;i<m;++i)
    {
        j = lps[i-1];
        while(j > 0 && pat[i] != pat[j])
            j = lps[j-1];
        if(pat[i] == pat[j])
            j++;
        lps[i] = j;
    }
}

bool searchPattern(string str, string pat)
{
    int n = str.length();
    int m = pat.length();
    string newstr = pat + "#" + str;
    int lps[m+n+1];
    computeLps(lps, m+n+1, newstr);
    
    int i = 0, j = 0;
    for(int i=0;i<m+n+1;++i)
        if(lps[i] == m)
            return 1;
    return 0;
}




// { Driver Code Starts.
int main()
{
    int t; cin>>t;
    
    while(t--)
    {
        string str, pat;
        cin>>str;
        cin>>pat;
        
        if(searchPattern(str, pat) == true)
            cout << "Present" <<endl;
        else cout << "Not present" <<endl;
    }
}

  // } Driver Code Ends