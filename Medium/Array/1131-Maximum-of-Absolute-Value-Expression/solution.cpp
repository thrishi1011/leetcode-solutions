class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();

        vector<int> temp1(n);
        vector<int> temp2(n);
        vector<int> temp3(n);
        vector<int> temp4(n);

        for(int k = 0; k < n; k++){
            temp1[k] = arr1[k] + arr2[k] + k;
            temp2[k] = arr1[k] + arr2[k] - k;
            temp3[k] = arr1[k] - arr2[k] + k;
            temp4[k] = arr1[k] - arr2[k] - k;
        }

        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        sort(temp3.begin(), temp3.end());
        sort(temp4.begin(), temp4.end());

        int max1 = temp1[n-1] - temp1[0];
        int max2 = temp2[n-1] - temp2[0];
        int max3 = temp3[n-1] - temp3[0];
        int max4 = temp4[n-1] - temp4[0];

        return max({max1, max2, max3, max4});
    }
};