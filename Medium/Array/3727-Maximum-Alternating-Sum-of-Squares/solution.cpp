class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        int x = (nums.size() + 1) / 2;

        for(int i = 0; i < nums.size(); i++){
            nums[i] = abs(nums[i]);
        }

        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());

        int cnt = 0;
        int k = 0;
        int n = temp.size();

        while(cnt < x && k < n){
            ans += 1LL * temp[k] * temp[k];
            cnt++;
            k++;
        }

        while(k < n){
            ans -= 1LL * temp[k] * temp[k];
            k++;
        }

        return ans;
    }
};