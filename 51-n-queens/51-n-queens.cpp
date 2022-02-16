class Solution {
public:
    int leftdiag[17], rightdiag[17], up[9];
    Solution()
    {
        memset(leftdiag, 0, sizeof(leftdiag));
        memset(rightdiag, 0, sizeof(rightdiag));
        memset(up, 0, sizeof(up));
    }
    // bool issafe(vector<string> ans, int x, int y, int n)
    // {
    //     return 1;
    // }
    void solve(vector<vector<string>> &result, vector<string> ans, int x, int n)
    {
        if(x == n)
        {
            result.push_back(ans);
            return;
        }
        for(int i=0;i<n;++i)
        {
            if(up[i] == 0 && leftdiag[n-1+x-i] == 0 && rightdiag[x+i] == 0)
            {
                ans[x][i] = 'Q';
                up[i] = 1;
                leftdiag[n-1+x-i] = 1;
                rightdiag[x+i] = 1;
                solve(result, ans, x+1, n);
                ans[x][i] = '.';
                up[i] = 0;
                leftdiag[n-1+x-i] = 0;
                rightdiag[x+i] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        string str;
        for(int i=0;i<n;++i)
            str.push_back('.');
        vector<string> ans(n, str);
        solve(result, ans, 0, n);
        return result;
    }
};