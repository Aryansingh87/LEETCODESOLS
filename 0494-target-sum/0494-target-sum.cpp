class Solution { 
public:
     int MOD = (int) 1e9+7;
 int f(int ind, int sum, vector<int> &num, vector<vector<int>> &dp){

if(ind == 0) {
if(sum == 0 && num[0] == 0) return 2;
if(sum == 0 || sum == num[0]) return 1;
return 0;

}
if(dp[ind][sum] != -1) return dp[ind] [sum];
int notTake = f(ind-1, sum, num, dp);
int take = 0;
if(num[ind] <= sum) take=f(ind-1, sum-num[ind], num, dp);

return dp[ind][sum] = (notTake + take) % MOD;
}
int findTargetSumWays(vector<int> &num, int target){

int n = num.size();

 int totSum = 0;
        for(auto &it: num) totSum += it;
        
       
        if(totSum - target < 0 || (totSum - target) % 2 != 0) return 0;
        
        int tar = (totSum - target) / 2;
        vector<vector<int>> dp(n, vector<int>(tar+1, -1));
       
return f(n-1  ,tar , num , dp);
}
};