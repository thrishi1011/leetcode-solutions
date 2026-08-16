class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int x = 0;
        int y = 0;
        int z = 0;
        
        for(int val : stones){
            if(val % 3 == 0) x++;
            if(val % 3 == 1) y++;
            if(val % 3 == 2) z++;
        }

        if(x % 2 == 0) return y > 0 && z > 0;

        return abs(y - z) > 2;
    }
};