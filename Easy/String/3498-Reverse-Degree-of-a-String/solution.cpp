class Solution {
public:
    int reverseDegree(string s) {
        int i = 1;
        int ans = 0;
        for(char ch : s){
            int k = ('z' - ch + 1) * i;
            ans += k;
            i++;
        }

        return ans;
    }
};