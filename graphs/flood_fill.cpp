// https://leetcode.com/problems/flood-fill/submissions/
// Idea: Make a recursion tree for every cell.

class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int prevColor){
        if(sr >= image.size() || sr < 0 || sc >= image[0].size() || sc < 0 || image[sr][sc] != prevColor)
            // sr and sc should not exceed the upper and lower limit.
            // neighbour cells should be of prevColor.
            return;
        image[sr][sc] = newColor;
        dfs(image, sr, sc+1, newColor,prevColor);
        dfs(image, sr+1, sc, newColor,prevColor);
        dfs(image, sr, sc-1, newColor,prevColor);
        dfs(image, sr-1, sc, newColor,prevColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor)     {
        int prevColor = image[sr][sc];
        if(newColor == prevColor)
            return image;
        dfs(image, sr, sc, newColor,prevColor);
        return image;
     
    }
};