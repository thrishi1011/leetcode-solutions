class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.length();
        vector<int> ans(n);

        for(int i = 0; i < n; i++){
            ans[i] = (i ^ seq[i]) & 1;
        }

        return ans;
    }
};