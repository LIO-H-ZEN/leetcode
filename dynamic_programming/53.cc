class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxnn = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            nums[i] = std::max(nums[i], nums[i-1]+nums[i]);
            if (nums[i] > maxnn) {
                maxnn = nums[i];
            }
        }
        return maxnn;
    }
};
