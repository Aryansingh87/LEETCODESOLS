class Solution {
public:

 int solve(vector<int>& stones , int currstoneidx , int prevjump ,  unordered_map<int , int>& mp ,vector<vector<int>>& dp){
    int n = stones.size();
  
    if(currstoneidx == n-1){
        return 1;
    }
    if(dp[currstoneidx][prevjump] !=-1){


    return dp[currstoneidx][prevjump];
}   bool ans = false;
    for(int nextjump = prevjump-1;nextjump<=prevjump+1;nextjump++){
   if(nextjump > 0){
    int nextstone = stones[currstoneidx] + nextjump;
    if(mp.find(nextstone)!=mp.end()){
  ans = ans || solve(stones , mp[nextstone] , nextjump , mp ,dp);
    }
   }
    }
    return dp[currstoneidx][prevjump] = ans;
 }
    bool canCross(vector<int>& stones)
     {
        int n = stones.size();
        if(n==0) return false;
        unordered_map<int , int> mp;

        vector<vector<int>> dp(n , vector<int>(n+1 , -1));
        if(n>1 && stones[1]!=1){
            return false;
        }
        for(int i=0;i<n;i++){ 
            mp[stones[i]] = i;

        }
        return solve(stones , 0 ,0 ,mp, dp);
    }
};