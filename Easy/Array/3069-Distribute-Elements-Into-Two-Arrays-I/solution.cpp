class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> vec1, vec2;

        vec1.push_back(nums[0]);
        vec2.push_back(nums[1]);

        for (int k = 2; k < n; k++) {
            if (vec1.back() > vec2.back()) {
                vec1.push_back(nums[k]);
            } else {
                vec2.push_back(nums[k]);
            }
        }

        vector<int> ans = vec1;
        for(int val : vec2)
            ans.push_back(val);

        return ans;
    }
};