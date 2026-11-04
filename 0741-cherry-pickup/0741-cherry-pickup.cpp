class Solution {
public:
 int f(int r1 , int c1 , int r2 , vector<vector<int>>& grid , vector<vector<vector<int>>> &dp){
    int c2 = r1+c1-r2;
    int n = grid.size() , m= grid[0].size();
    if(r1>=n || r2>=n || c1>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2] ==-1){
        return INT_MIN;
    }
    if(dp[r1][c1][r2]!=-1){
        return dp[r1][c1][r2];
    }
     if(r1==n-1 && c1==n-1)
        {
            return grid[r1][c1];
        }
    int maxi = grid[r1][c1];
    if(r1!=r2){
        maxi += grid[r2][c2];
    }
    int value = max(f(r1+1 , c1 , r2+1 , grid , dp) , f(r1 , c1+1 , r2 , grid , dp));
      value = max(value , f(r1+1 , c1 , r2 , grid , dp));
        value = max(value , f(r1 , c1+1 , r2+1 , grid , dp));
        maxi = maxi + value;
        return dp[r1][c1][r2] = maxi;
 }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size() , m= grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>( m , vector<int>(m , -1)));
         return max(0 , f(0,0,0 , grid , dp));
    }
};