//https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1#

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    void bfs(int i, vector<int> &vis, vector<int> &bfsTraverse, vector<int> adj[]){
        queue<int> q;
        vis[i] = 1;
        q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            bfsTraverse.push_back(node);
            for(int it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
    }
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        vector<int> bfsTraverse;
        bfs(0, vis, bfsTraverse, adj);
        // for(int i=0; i<V; i++){
        //     if(!vis[i]){
        //         bfs(i, vis, bfsTraverse, adj);
        //     }
        // }
        return bfsTraverse;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends