class Solution {
public:
    int minimumDeletions(string s) {
         int ans = 0 , b=0;

         for(char ch : s){
            if(ch=='b'){
                b++;
            }else if(b>0){
                ans++;
                b--;
            }
         }
         return ans;
    }
};