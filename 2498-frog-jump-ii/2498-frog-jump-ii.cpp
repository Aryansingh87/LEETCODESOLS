class Solution {
public:
    int maxJump(vector<int>& stones) {
          int n = stones.size();
          if(n==2) return stones[1] - stones[0];
           long long diff=0;
          for(int i=0;i<n-2;i++){
            diff = max(diff , (long long) stones[i+2] - stones[i]);
          }
          return diff;
    }
};