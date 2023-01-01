class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i+1);
            for (int j = 0; j < i+1; ++j) {
                if (j == 0 || j == i) {
                    ret[i][j] = 1;
                } else {
                    ret[i][j] = ret[i-1][j-1] + ret[i-1][j];
                }
            }
        }
        return ret;
    }
};
