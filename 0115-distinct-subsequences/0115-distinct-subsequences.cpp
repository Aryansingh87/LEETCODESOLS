class Solution {
public:
int f(int i , int j , string &s , string &t , vector<vector<int>> &dp){
    if(j<0) return 1;
    if(i<0) return 0;
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int match=0;
    if(s[i]==t[j]){
        match = f(i-1,j-1 , s, t, dp)+ f(i-1 , j , s, t, dp);
    }else{
        match = f(i-1 , j , s , t, dp);
    }
    return dp[i][j] = match;
}
    int numDistinct(string s, string t) {
        int n = s.size() , m = t.size();
        vector<vector<int>> dp(n , vector<int>(m , -1));
        return f(n-1 , m-1 , s , t, dp);
    }
};