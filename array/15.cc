class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int t0 = nums[i];
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                // 双指针（排好序下，一头一尾）想让和变大，就只能向右挪j，反之亦然.
                if (nums[i] + nums[j] + nums[k] > 0) {
                    --k;
                } else if (nums[i] + nums[j] + nums[k] < 0) {
                    ++j;
                } else {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    int t1 = nums[j], t2 = nums[k];
                    // 在找到一个解后，跳过所有重复的j.
                    for (; j < k; ++j) {
                        if (nums[j] != t1) {
                            break;
                        }
                    }
                    // 类似
                    for (; k > j; --k) {
                        if (nums[k] != t2) {
                            break;
                        }
                    }
                }
            }
            // 类似.
            for (; i < nums.size(); ++i) {
                if (nums[i] != t0) {
                    break;
                }
            }
            // 注意最外层是for loop，所以要减1.
            --i;
        }
        return ret;
    }
};
