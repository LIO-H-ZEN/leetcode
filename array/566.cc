class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int nr = mat.size();
        if (nr == 0) {
            return {};
        }
        int nc = mat[0].size();
        if (r * c != nr * nc) {
            return mat;
        }
        vector<vector<int>> ret(r, vector<int>(c));
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                int rr = (i * c + j) / nc; // the corresponding i of mat.
                int cc = (i * c + j) % nc; // the corresponding j of mat.
                ret[i][j] = mat[rr][cc];
            }
        }
        return ret;
    }
};
