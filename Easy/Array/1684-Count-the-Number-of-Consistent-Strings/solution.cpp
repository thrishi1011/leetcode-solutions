class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> alpha(26, false);
        int cnt = words.size();

        for(char ch : allowed) alpha[ch - 'a'] = true;

        for(auto word : words){
            for(char ch : word){
                if(!alpha[ch - 'a']){
                    cnt--;
                    break;
                }
            }
        }

        return cnt;
    }
};