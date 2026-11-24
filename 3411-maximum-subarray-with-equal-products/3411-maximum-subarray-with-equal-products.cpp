
class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
         long long MAX_PROD = 25200; 

        for (int i = 0; i < n; i++) {

      long long prod = 1;
            long long g = 0;
             long long lcm = 1;

            for (int j = i; j < n; j++) {

                unsigned x = nums[j];

                prod *= x;
                if(prod > MAX_PROD){
            break;
                }

                g = gcd(g, (long long)x);

                lcm = (lcm / gcd(lcm, (long long)x)) * x;

                if (prod == lcm * g) {
                    ans = max(ans, j - i + 1);
                }
            }
        }

        return ans;
    }
};
