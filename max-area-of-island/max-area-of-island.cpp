class Solution {
public:
    bool issafe(int i, int j, int n ,int m)
    {
        return i >= 0 and i < n and j >= 0 and j < m;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        int ans = 0;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                if(grid[i][j] == 1)
                {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j] = -1;
                    int area = 0;
                    while(!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        ++ area;
                        for(int k=0;k<4;++k)
                        {
                            int nx = x+dx[k];
                            int ny = y+dy[k];
                            bool flag = issafe(nx,ny,r,c);
                            if(flag and grid[nx][ny] > 0)
                            {
                                grid[nx][ny] = -1;
                                q.push({nx, ny});
                            }
                        }
                    }
                    ans = max(area, ans);
                }
            }
        }
        return ans;
    }
};