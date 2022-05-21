//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1#
//Using bfs traversal, find all the 8 positions and push into the queue and then pop one by one.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool inside(int x, int y, int N){
        if(x<1 || x>N || y<1 || y>N)
            return false;
        return true;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>> chess(N+1,vector<int>(N+1,0));
	    int dx[] = {2,2,-2,-2,1,-1,1,-1};
	    int dy[] = {1,-1,1,-1,2,2,-2,-2};
	    int x = KnightPos[0], y = KnightPos[1];
	    queue<vector<int>> q;
	    q.push({x,y,0});
	    chess[x][y] = 1;
	    while(!q.empty()){
	        vector<int> cor = q.front();
	        q.pop();
	        if(cor[0]==TargetPos[0] && cor[1]==TargetPos[1])
	            return cor[2];
	        for(int i=0; i<8; i++){
	            int tx = cor[0]+dx[i];
	            int ty = cor[1]+dy[i];
    	        if(inside(tx, ty, N, chess) && chess[tx][ty]==0){
    	            q.push({tx,ty,cor[2]+1});
    	            chess[tx][ty]==1;
    	        }
	        }
	    }
	    return 0;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends