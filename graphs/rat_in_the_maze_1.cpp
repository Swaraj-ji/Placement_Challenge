//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1#
//idea: while returning from the path mark it 1 again.

// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void dfsMaze(int i, int j, vector<vector<int>> &m, vector<string> &paths, string str){
        if(i<0 || i>=m.size() || j<0 || j>=m.size() || m[i][j]!=1){
            return;
        }
        if(i==m.size()-1 && j==m.size()-1){
            paths.push_back(str);
            return;
        }
        m[i][j] = -1;
        
        dfsMaze(i, j+1, m, paths, str+"R");
        dfsMaze(i+1, j, m, paths, str+"D");
        dfsMaze(i, j-1, m, paths, str+"L");
        dfsMaze(i-1, j, m, paths, str+"U");

        m[i][j] = 1;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> paths;
        dfsMaze(0,0,m,paths,"");
        
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