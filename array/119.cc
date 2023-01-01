class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret;
        ret.resize(rowIndex+1, 1);
        int pre_val = 1;
        for (int j = 2; j <= rowIndex; ++j) {
            for (int i = 1; i < j; ++i) {
                int tmp_val = ret[i];
                ret[i] = ret[i] + pre_val;
                pre_val = tmp_val;
            }
        }
        return ret;
    }
};
