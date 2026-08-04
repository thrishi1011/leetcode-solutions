class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int minnum = nums[0];
        int maxnum = nums[0];

        for (int num : nums) {
            if (num < minnum) minnum = num;
            if (num > maxnum) maxnum = num;
        }

        for (int i = minnum; i <= maxnum; i++) {
            bool found = false;
            for (int num : nums) {
                if (num == i) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};