class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+1);
        int pre_val = 0;
        for (int j = 0; j <= rowIndex; ++j) {
            for (int i = 0; i <= j; ++i) {
                if (i == 0 || i == j) {
                    ret[i] = 1;
                    pre_val = 1;
                } else {
                    int tmp_val = ret[i];
                    ret[i] = ret[i] + pre_val;
                    pre_val = tmp_val;
                }
            }
        }
        return ret;
    }
};
