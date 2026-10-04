class Solution {
public:
    bool checkValidString(string s) {
        int left = 0;
        int right = 0;

        for (char ch : s) {
            if (ch == '(') {
                left++;
                right++;
            }
            else if (ch == ')') {
                left--;
                right--;
            }
            else {
                left--;
                right++;
            }

            if (right < 0)
                return false;

            left = max(left, 0);
        }

        return left == 0;
    }
};