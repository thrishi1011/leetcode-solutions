class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i = 1;

        while (true) {
            int target = i * k;
            bool found = false;

            for (int num : nums) {
                if (num == target) {
                    found = true;
                    break;
                }
            }
            
            if (!found)
                return target;
            i++;
        }
    }
};
