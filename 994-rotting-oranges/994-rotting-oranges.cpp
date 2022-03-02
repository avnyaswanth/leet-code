class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int total = 0, minutes = 0;
        queue<pair<int, int>> rotten;
        for(int i=0;i<grid.size();++i)
        {
            for(int j=0;j<grid[0].size();++j)
            {
                if(grid[i][j] != 0)
                    total++;        // total number of oranges.. rotten + normal
                if(grid[i][j] == 2)
                    rotten.push({i, j});
            }
        }
        
        int count = 0;      // to find the total rotten
        
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        while(!rotten.empty())
        {
            int k = rotten.size();
            count += k;
            while(k--)
            {
                int x = rotten.front().first, y = rotten.front().second;
                rotten.pop();
                for(int i=0;i<4;++i)
                {
                    int nx = x+dx[i], ny = y+dy[i];
                    if(nx < 0|| nx >= n || ny < 0 || ny >= m || grid[nx][ny] != 1)
                        continue;
                    grid[nx][ny] = 2;
                    rotten.push({nx, ny});
                }
            }
            if(!rotten.empty())
                minutes++;
        }
        return total == count ? minutes : -1;   // if total rotten equals total oranges return mins else -1
    }
};