//https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1/#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> &vis, vector<int> &dfsTraverse, vector<int> adj[]){
        if(!vis[node]){
            vis[node] = 1;
            dfsTraverse.push_back(node);
        }
        for(int i: adj[node]){
            if(!vis[i]){
                dfs(i, vis, dfsTraverse, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> dfsTraverse;
        dfs(0, vis, dfsTraverse, adj);
        return dfsTraverse;
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
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends