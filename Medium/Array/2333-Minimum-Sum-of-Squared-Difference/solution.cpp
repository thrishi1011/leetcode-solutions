class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size(), m = 0;
        long long k = 1LL * k1 + k2;
        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = abs(nums1[i] - nums2[i]);
            m = max(m, a[i]);
        }

        vector<int> freq(m + 1, 0);

        for (int x : a)
            freq[x]++;

        for (int i = m; i > 0 && k > 0; i--) {
            int t = min((long long)freq[i], k);
            freq[i] -= t;
            freq[i - 1] += t;
            k -= t;
        }

        long long ans = 0;

        for (int i = 1; i <= m; i++)
            ans += 1LL * freq[i] * i * i;

        return ans;
    }
};