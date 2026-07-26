class Solution {
public:
    int semiOrderedPermutation(vector<int>& n) {
        
        int first = find(begin(n), end(n), 1) - begin(n);
        int last = find(begin(n), end(n), n.size()) - begin(n);

        return first + (n.size() - last - 1) - (first > last);
    }
};