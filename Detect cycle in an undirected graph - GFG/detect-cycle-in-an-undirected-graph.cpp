// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool isCyclicUtil(int v, vector<int> adj[], bool visited[], int parent) {
        // vis[ver] = 1;
        // for(auto curV : adj[ver]) {
        //     if(!vis[curV]) {
        //         if(dfs(curV, adj, vis, ver))
        //             return true;
        //     }
        //     else if(par != curV)
        //         return true;
        // }
        // return false;
        visited[v] = true;
 
    // Recur for all the vertices
    // adjacent to this vertex
    vector<int>::iterator i;
    for (i = adj[v].begin(); i !=
                       adj[v].end(); ++i)
    {
         
        // If an adjacent vertex is not visited,
        //then recur for that adjacent
        if (!visited[*i])
        {
           if (isCyclicUtil(*i, adj, visited, v))
              return true;
        }
 
        // If an adjacent vertex is visited and
        // is not parent of current vertex,
        // then there exists a cycle in the graph.
        else if (*i != parent)
           return true;
    }
    return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // vector<bool> vis(V, 0);
        // for(int i=0;i<V;++i) {
        //     if(!vis[i]) {
        //         if(dfs(i, adj, vis, -1));
        //             return true;
        //     }
        // }
        // return false;
        bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper
    // function to detect cycle in different
    // DFS trees
    for (int u = 0; u < V; u++)
    {
       
        // Don't recur for u if
        // it is already visited
        if (!visited[u])
          if (isCyclicUtil(u, adj, visited, -1))
             return true;
    }
    return false;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends