class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int len = 0;

        int xr = 0;
        bool nonZero = false;

        while(j < n){
            xr ^= nums[j];

            if(nums[j] != 0)
                nonZero = true;

            j++;
        }

        if(xr != 0){
            len = n;
            return len;
        }

        if(nonZero){
            len = n - 1;
            return len;
        }

        return 0;
    }
};