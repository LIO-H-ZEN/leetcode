class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int st = 0, ed = nums.size()-1, idx = nums.size()-1;
        vector<int> ret(nums.size());
        while (st != ed) {
            if (abs(nums[ed]) >= abs(nums[st])) {
                ret[idx] = nums[ed];
                --ed;
                --idx;
            } else {
                ret[idx] = nums[st];
                ++st;
                --idx;
            }
        }
        ret[idx] = nums[st];
        --idx;
        for (int i = 0; i < ret.size(); ++i) {
            ret[i] = ret[i] * ret[i];
        }
        return ret;
    }
};
