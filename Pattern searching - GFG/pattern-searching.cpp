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

bool searchPattern(string str, string pat)
{
    int n = str.length();
    int m = pat.length();
    int d = 26;
    int q = 101;
    int ph = 0, th = 0;
    int h = 1;
    
    for(int i=0;i<m-1;++i)
        h = (h * d) % q;
    
    for(int i=0;i<m;++i)
    {
        ph = (d * ph + (pat[i] - 'a')) % q;
        th = (d * th + (str[i] - 'a')) % q;
    }
    for(int i=0;i<=n-m;++i)
    {
        if(ph == th)
        {
            bool flag = 1;
            for(int j=0;j<m;++j)
            {
                if(pat[j] != str[i+j])
                {
                    flag = 0;
                    break;
                }
            }
            if(flag)
                return true;
        }
        if(i < n-m)
        {
            th = (d*(th - h*(str[i]-'a')) + (str[i+m]-'a')) % q;
            if(th < 0)
                th += q;
        }
    }
    return false;
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