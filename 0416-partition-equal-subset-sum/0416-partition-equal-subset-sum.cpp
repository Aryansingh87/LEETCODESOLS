class Solution {
public:

  bool  subsetsumtok(int n , int k , vector<int> &arr){
    vector<bool> prev(k+1, 0), cur(k+1, 0);
prev[0] = cur[0] = true;
if(arr[0]<=k){
prev[arr[0]] = true;
}
for(int i =1;i<n;i++) {
for(int target =1;target <= k;target++) {
bool notTake = prev[target];
bool take = false;
if(arr[i] <= target) take = prev[target-arr[i]];
cur[target] = take | notTake;

}
prev = cur;


  }
  return prev[k];
  }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
        }
            if(sum%2!=0){
                return false;
            }
        int target = sum/2;
        return subsetsumtok(n , target , nums);
       
    }
};