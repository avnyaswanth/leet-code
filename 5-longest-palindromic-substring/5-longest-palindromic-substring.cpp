class Solution {
public:
    string palindrome(string s, int l, int r)
    {
        int n = s.length();
        while(l >= 0 && r < n && s[l] == s[r])
            l--, r++;
        l++, r--;
        string str = s.substr(l, r-l+1);
        return str;
    }
    
    void maxcheck(string str, string &ans)
    {
        if(str.length() > ans.length())
            ans = str;
    }
    string longestPalindrome(string s) {
        int n(s.length());
        int l = 0, r = 0;
        string str = "";
        string ans = "";
        for(int i=0;i<n;++i)
        {
            // odd length pal check
            l = i, r = i;
            str = palindrome(s, l, r);
            maxcheck(str, ans);
            // even length pal check
            l = i, r = i+1;
            str = palindrome(s, l, r);
            maxcheck(str, ans);
        }
        return ans;
    }
};