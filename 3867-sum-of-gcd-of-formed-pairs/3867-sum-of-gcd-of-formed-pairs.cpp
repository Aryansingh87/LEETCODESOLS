class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        
        
        int maxi  = 0;

        for (auto& x : nums) {
            maxi = max(maxi, x);
            x = gcd(x, maxi);
        }

        ranges::sort(nums);

        long long ans = 0;
        for (int i = 0, j = nums.size() - 1; i < j; i++, j--)
            ans += gcd(nums[i], nums[j]);

        return ans;
    }
};