class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ret = 10e5, minn = 10e5;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i) {
            int j = i+1, k = nums.size()-1;
            while (j < k) {
                int diff = nums[i] + nums[j] + nums[k] - target;
                if (std::abs(diff) < minn) {
                    minn = std::abs(diff);
                    ret = nums[i] + nums[j] + nums[k];
                }
                if (diff > 0) {
                    --k;
                } else {
                    ++j;
                }
            }
        }
        return ret;
    }
};
