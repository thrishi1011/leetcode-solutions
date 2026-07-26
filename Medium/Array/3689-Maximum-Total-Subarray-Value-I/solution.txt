class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long minnum = INT_MAX;
        long long maxnum = INT_MIN;

        for(long long val : nums){
            minnum = min(minnum, val);
            maxnum = max(maxnum, val);
        }

        return (abs(minnum - maxnum) * k);
    }
};