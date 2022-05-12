//https://leetcode.com/problems/number-of-islands/submissions/

class Solution {
public:
    void dfsLand(int i, int j, vector<vector<char>>& grid){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1')
            return;
        grid[i][j] = -1;
        dfsLand(i,j+1,grid);
        dfsLand(i+1,j,grid);
        dfsLand(i,j-1,grid);
        dfsLand(i-1,j,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int island = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
               if(grid[i][j] == '1'){
                   dfsLand(i,j,grid);
                   island++;
               }
            }
        }
        
        return island;
    }
};