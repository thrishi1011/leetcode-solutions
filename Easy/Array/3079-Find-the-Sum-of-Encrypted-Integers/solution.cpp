class Solution {
public:

    int encrypt(int x){
        string s = to_string(x);
        int n = s.length();
        sort(s.begin(), s.end());
        int maxnum = s[n - 1] - '0';
        int num = pow(10, n);
        return ((num-1)/9) * maxnum;
    }

    int sumOfEncryptedInt(vector<int>& nums) {
        int ans = 0;
        for(int val : nums){
            ans += encrypt(val);
        }

        return ans;
    }
};