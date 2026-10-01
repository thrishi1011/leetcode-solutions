class Solution {
public:
    bool isValid(string s) {
        string temp = "";

        for (int i = 0; i < s.length(); i++) {
            char c = s[i];

            if (c == '(' or c == '{' or c == '[') {
                temp += c;
            } 
            else {
                if (temp.empty()) {
                    return false;
                }

                char last = temp[temp.length() - 1];

                if ((c == ')' and last == '(') or
                    (c == '}' and last == '{') or
                    (c == ']' and last == '[')) {
                    temp.pop_back();
                } 
                else {
                    return false;
                }
            }
        }

        if (temp.empty()) {
            return true;
        } 
        else {
            return false;
        }
    }
};