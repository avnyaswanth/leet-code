class Solution {
public:
    bool isvalid(int i, int j, int n, int m)
    {
        return i>=0 && i<n && j>=0 && j<m;
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int r = image.size();
        int c = image[0].size();
        int dx[] = {1,-1,0,0};
        int dy[] = {0,0,1,-1};
        queue<pair<int,int>> q;
        q.push({sr, sc});
        int originalcolor = image[sr][sc];
        while(!q.empty())
        {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            image[i][j] = newColor;
            for(int k=0;k<4;++k)
            {
                int nx = i+dx[k];
                int ny = j+dy[k];
                if(isvalid(nx, ny, r,c) && image[nx][ny] != newColor && image[nx][ny] == originalcolor)
                    q.push({nx, ny});
            }
        }
        return image;
    }
};