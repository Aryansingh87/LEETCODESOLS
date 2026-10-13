class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
         int n = cost.size();
        vector<int> dp(n+1,0);
       
       
           dp[n]=0;
        for(int i=n-1;i>=0;i--){
           int next_step = dp[i + 1];
        int two_steps = (i + 2 <= n) ? dp[i + 2] : 0;
        dp[i] = cost[i] + min(next_step, two_steps);
        }
          return min(dp[0], dp[1]);
    }
};