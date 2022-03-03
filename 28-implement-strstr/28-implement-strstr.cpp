class Solution {
public:
    int strStr(string haystack, string needle) {
        string newstr = needle + "#" + haystack;
        int n = haystack.length();
        int m = needle.length();
        int idx = -1;
        if(m > n)
            return idx;
        int lps[n+m+1];
        lps[0] = 0;
        int j = 0;
        for(int i=1;i<n+m+1;++i)
        {
            j = lps[i-1];
            while(j > 0 && newstr[i] != newstr[j])
                j = lps[j-1];
            if(newstr[i] == newstr[j])
                j++;
            lps[i] = j;
        }
        for(int i=0;i<n+m+1;++i)
        {
            if(lps[i] == m)
            {
                idx = i-2*m;
                break;
            }
        }
        return idx;
    }
};