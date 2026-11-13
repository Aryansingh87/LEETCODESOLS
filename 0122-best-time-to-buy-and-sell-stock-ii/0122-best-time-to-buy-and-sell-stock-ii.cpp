class Solution {
public:
//   long f(int idx  , int buy , vector<int>& prices , vector<vector<int>> &dp){
//     int n = prices.size();
        
//     if(idx==n) return 0;
//     if(dp[idx][buy]!=-1){
//         return dp[idx][buy];
//     }
//     long profit=0;
//     if(buy){
//                profit = max(-prices[idx]+f(idx+1 , 0 , prices , dp) , 0+f(idx+1 , 1 , prices , dp));
//     }
//     else{
//     profit = max(prices[idx]+f(idx+1 , 1 , prices , dp) , 0+f(idx+1 , 0 , prices , dp));
//     }
//     return dp[idx][buy] =  profit;
//   }
    int maxProfit(vector<int>& prices) {
             int n = prices.size();
             vector<vector<int>> dp(n+1 , vector<int>(2 , 0));
             dp[n][0] = dp[n][1] = 0;
             for(int idx=n-1;idx>=0;idx--){
                for(int buy=0;buy<=1;buy++){
                    long profit=0;
    if(buy){
               profit = max(-prices[idx]+dp[idx+1][0] , 0+dp[idx+1][1]);
    }
    else{
    profit = max(prices[idx]+dp[idx+1][1] , 0+dp[idx+1][0]);
    }
     dp[idx][buy] =  profit;
                }
             }
             return dp[0][1];
    }
};