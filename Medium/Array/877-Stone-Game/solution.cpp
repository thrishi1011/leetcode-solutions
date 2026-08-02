class Solution {
public:
    int dp[501][501];

    int solver(vector<int> p, int i, int j){
        if(i == j) return p[i];

        if(dp[i][j] != INT_MIN) return dp[i][j];

        int left = p[i] - solver(p, i+1, j);
        int right = p[j] - solver(p, i, j-1);

        return dp[i][j] = max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        for(int i = 0; i < 501; i++)
            for(int j = 0; j < 501; j++)
                dp[i][j] = INT_MIN;

        return solver(piles, 0, n-1) >= 0;
    }
};