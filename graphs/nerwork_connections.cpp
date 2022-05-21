//Number of Operations to Make Network Connected
//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    void dfs(int node, vector<int> &vis, vector<int> adj[]){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it])
                dfs(it, vis, adj);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
        vector<int> adj[n];
        for(auto e : connections){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        int comp = 0;
        vector<int> vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                comp++;
                dfs(i, vis, adj);
            }
        }
        return comp-1;
    }
};