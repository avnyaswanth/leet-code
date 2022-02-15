class Solution {
public:
    int pal[17][17];
    Solution()
    {
        memset(pal, -1, sizeof(pal));
    }
    bool ispalindrome(int i, int j, string s)
    {
        int start = i, end = j;
        if(pal[start][end] != -1)
            return pal[start][end];
        while(i < j)
        {
            if(s[i] != s[j])
            {
                pal[start][end] = 0;
                return false;
            }
            i++, j--;
        }
        pal[start][end] = 1;
        return true;
    }
    void partitionUtil(vector<vector<string>> &ans, vector<string> vec, string s, int i, int n)
    {
        if(i == n)
        {
            ans.push_back(vec);
            return ;
        }
        string str = "";
        for(int j=i;j<n;++j)
        {
            str += s[j];
            // int start = i, end = j;
            if(ispalindrome(i, j, s))
            {
                vec.push_back(str);
                partitionUtil(ans, vec, s, j+1, n);
                vec.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        partitionUtil(ans, vec, s, 0, s.length());
        return ans;
    }
};