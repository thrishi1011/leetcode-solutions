class Solution {
public:
    string convert(string s, int numRows) {

        if(numRows == 1) return s;

        vector<string> rows(numRows);
        int curRow = 0;
        bool goingDown = true;

        for(char c : s) {
            rows[curRow] += c;

            if(curRow == 0) goingDown = true;

            else if(curRow == numRows-1) goingDown = false;

            if(goingDown) curRow++;
            else curRow--;
        }

        string ans = "";
        for(string &row : rows) ans += row;

        return ans;
    }
};