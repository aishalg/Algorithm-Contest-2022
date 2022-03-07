class Solution {
public:
    int N,M;
    vector<vector<int>>dp;
    int dfs(int x, int y, vector<vector<int>>& matrix){
        if(dp[x][y])      // check if the value is already calculated
            return dp[x][y];
        
        vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        int ans=1;
        
        for (int i=0;i<4;i++){   // iterate in all the 4 directions
            int X=x+dir[i][0];
            int Y=y+dir[i][1];
            
            if (X<0 || X>=N || Y<0 || Y>=M) // number should be in bound
                continue;
            if (matrix[X][Y]<=matrix[x][y]) // path should be increasing
                continue;
            ans=max(ans,1+dfs(X,Y,matrix));  // func call again to move into next direction
            
        }
        
        return dp[x][y]=ans;   // storing the max value in dp table
        
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
       int n=matrix.size();          // check the length 
        if (n==0)
            return 0;
        
        int m=matrix[0].size();
        N=n;       // insert the number of rows 
        M=m;       // columns
        dp=vector<vector<int>>(n,vector<int>(m,0));  // dp table
        int res=0;
        
        for (int i=0;i<n;i++){          // result for all the possible values
            for (int j=0;j<m;j++){
                res=max(res,dfs(i,j,matrix)); // update the result
            }
        }
        
        return res;    // maximum of all the paths
    }
};