class Solution {
public:
int f(string &s , int i , int j ,  vector<vector<int>> &dp){
     if(i>=j){
        return 0;
     }
     if(dp[i][j]!=-1){
        return dp[i][j];
     }
      return dp[i][j]=s[i]==s[j] ? f(s,i+1,j-1 , dp) : 1+min(f(s,i+1,j , dp),f(s,i,j-1 , dp));
     }

    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n , vector<int>(n , -1));
      return f(s , 0 , n-1 , dp);
    }
};