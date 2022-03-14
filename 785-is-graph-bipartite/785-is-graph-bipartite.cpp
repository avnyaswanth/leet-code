class Solution {
public:
    bool bfs(int v, vector<vector<int>> adj, int col[])
    {
        queue<int> q;
	    q.push(v);
	    col[v] = 0;
	    while(!q.empty())
	    {
	        int ver = q.front();
	        q.pop();
	        for(auto node : adj[ver])
	        {
	            if(col[node] == -1)
                {
                    col[node] = col[ver] ^ 1; 
                    q.push(node);
                }
	            else if(col[node] == col[ver])
	                return false;
	        }
	    }
	    return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int col[graph.size()];
	    memset(col, -1, sizeof col);
	    for(int i=0;i<graph.size();++i)
	    {
	       if(col[i] == -1)
	       {
	           if(!bfs(i, graph, col))
	            return false;
	       }
	    }
	    return true;
    }
};