class Solution {
public:
    bool checkDivisibility(int n) {
        int a = 1;
        int b = 0;
        int l = n;
        while(l > 0){
            int k = l % 10;
            a *= k;
            b += k;
            l /= 10;
        }

        return (n % (a+b) == 0) ? true : false;
    }
};