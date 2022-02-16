class Solution {
public:
    bool issafe(vector<string> ans, int x, int y, int n)
    {
        int dx(x), dy(y);
        while(dx > 0)   // move up
        {
            dx --;
            if(ans[dx][dy] == 'Q')
                return false;
        }
        dx = x;
        while(dx > 0 && dy > 0)
        {
            dx--, dy--;
            if(ans[dx][dy] == 'Q')
                return false;
        }
        dx = x, dy = y;
        while(dy < n-1 && dx > 0)
        {
            dy++, dx--;
            if(ans[dx][dy] == 'Q')
                return false;
        }
        return true;
    }
    void solve(vector<vector<string>> &result, vector<string> ans, int x, int n)
    {
        if(x == n)
        {
            result.push_back(ans);
            return;
        }
        for(int i=0;i<n;++i)
        {
            if(issafe(ans, x, i, n))
            {
                ans[x][i] = 'Q';
                solve(result, ans, x+1, n);
                ans[x][i] = '.';
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