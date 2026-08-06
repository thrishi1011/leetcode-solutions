class Solution {
public:

    int product(int x){
        int prod = 1;
        while(x > 0){
            int r = x % 10;
            prod *= r;
            x /= 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        int ans;
        for(int i = n; i <= 100; i++){
            if(product(i) % t == 0){
                ans = i;
                break;
            }
        }

        return ans;
    }
};