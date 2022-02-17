// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    bool visited[6][6];
    bool canmove(int i, int j, int n, vector<vector<int>> &maze)
    {
        return i >= 0 && i < n && j >=0  && j < n && maze[i][j] == 1;
    }
    void findSol(vector<vector<int>> &maze, vector<string> &paths, string path, int i, int j, int n)
    {
        if(i == n-1 && j == n-1 && maze[i][j] == 1)
        {
            // visited[i][j] = 0;
            paths.push_back(path);
            return ;
        }
        
        // down, left, right, up
      
        int di[] = {+1, 0, 0, -1}; 
        int dj[] = {0, -1, 1, 0}; 
        string direction = "DLRU";
        for(int k=0;k<4;++k)
        {
            int ni = i + di[k];
            int nj = j + dj[k];
            if(canmove(ni, nj, n, maze) && visited[ni][nj] == 0)
            {
                path.push_back(direction[k]);
                visited[ni][nj] = 1;
                findSol(maze, paths, path, ni, nj, n);
                path.pop_back();
                visited[ni][nj] = 0;
            }
        }
    }
    vector<string> findPath(vector<vector<int>> &maze, int n) {
        vector<string> paths;
        string path;
        memset(visited, 0, sizeof(visited));
        visited[0][0] = 1;
         if(maze[0][0] == 1 && maze[n-1][n-1] == 1)
            findSol(maze, paths, path, 0, 0, n);
        return paths;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends