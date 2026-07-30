class Solution {
public:
    int minimumPushes(string A) {
        auto q = A.size() >> 3, r = A.size() & 7;
        auto ans = (q << 2) + r;
        
        return (ans * (q + 1));
    }
};