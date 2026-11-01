class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount+1 , 0);
            
   dp[0]=1;
   for(long long c:coins){
    if(c > amount) continue;
    for(long long a=c;a<=amount;a++){
       dp[a] = dp[a] + dp[a-c];
    }
   }
    return dp[amount];

    }
};