// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool bfs(int v, vector<int>adj[], int col[])
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
	bool isBipartite(int V, vector<int>adj[]){
	    int col[V];
	    memset(col, -1, sizeof col);
	    for(int i=0;i<V;++i)
	    {
	       if(col[i] == -1)
	       {
	           if(!bfs(i, adj, col))
	            return false;
	       }
	    }
	    return true;
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends