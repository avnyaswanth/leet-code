class Solution {
public:
    int strStr(string haystack, string needle) {
        string newstr = needle + "#" + haystack;
        int n = haystack.length();
        int m = needle.length();
        int idx = -1;
        if(m > n)
            return idx;
        if(m == 0)
            return 0;
        int t = n+m+1;
        int z[t];
        memset(z, 0, sizeof(z));
        int l, r;
        for(int i=1, l = 0, r = 0;i<t;++i)
        {
            if(i <= r)
                z[i] = min(r-i+1, z[i-l]);
            while(i+z[i] < t && newstr[z[i]] == newstr[i+z[i]])
                z[i]++;
            if(i+z[i]-1 > r)
                l = i, r = i+z[i]-1;
        }
        for(int i=0;i<t;++i)
        {
            if(z[i] == m)
            {
                idx = i-(m+1);
                break;
            }
        }
        return idx;
    }
};