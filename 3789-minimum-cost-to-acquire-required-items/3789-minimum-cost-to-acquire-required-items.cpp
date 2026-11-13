class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long total = min(need1, need2);



return total * min(cost1 + cost2, costBoth)  + (need1 - total) * min(cost1,costBoth)  + (need2 - total) * min(cost2, costBoth);
    }
};