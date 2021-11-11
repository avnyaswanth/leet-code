class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int visi[302][302];   //visited array to mark cells
    int n,m;
    
    //check whether 
    bool check(int r,int c){
        if(r>=n || c>=m || r<0 || c<0)return 0;
        return 1;
    }
	
    void dfs(int r,int c,vector<vector<char>>& g){
        
        visi[r][c]=1;  //mark the cell as visited
        for(int i=0;i<4;i++){//try all 4 directions
            int nx=dx[i]+r;
            int ny=dy[i]+c;
            if(check(nx,ny) and g[nx][ny]=='1' and !visi[nx][ny]){  //valid cell and water and not visited
                dfs(nx,ny,g);
            }
        }
    }
    

    int numIslands(vector<vector<char>>& grid) {
        n=grid.size();m=grid[0].size();
		
        memset(visi,0,sizeof(visi));   //initialising visi array as 0
        int comp=0;  //number of connected components 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1' and !visi[i][j]){
                    dfs(i,j,grid);
                    comp++;
                }
            }
        }
        return comp;
        
    }
};