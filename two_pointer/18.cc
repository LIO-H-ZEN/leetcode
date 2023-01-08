class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                int k = j+1, h = nums.size()-1;
                while (k < h) {
					// 防止官方新增的用例导致int溢出：[1000000000,1000000000,1000000000,1000000000]  -294967296
                    int64_t s = ((int64_t)nums[i] + (int64_t)nums[j] + (int64_t)nums[k] + (int64_t)nums[h]);
                    if (s < target) {
                        ++k;
                    } else if (s > target) {
                        --h;
                    } else {
                        ret.push_back({nums[i], nums[j], nums[k], nums[h]});
                        int tk = nums[k], th = nums[h];
                        for (; k < h; ++k) {
                            if (tk != nums[k]) {break;}
                        }
                        for (; h > k; --h) {
                            if (th != nums[h]) {break;}
                        }
                    }
                }
                int tj = nums[j];
                for (; j < nums.size(); ++j) {
                    if (tj != nums[j]) {break;}
                }
                --j;
            }
            int ti = nums[i];
            for (; i < nums.size(); ++i) {
                if (ti != nums[i]) {break;}
            }
            --i;
        }
        return ret;
    }
};
