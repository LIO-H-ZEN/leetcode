class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre_val = nums[0];
        int j = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == pre_val) {
                continue;
            }
            nums[j] = nums[i];
            pre_val = nums[i];
            ++j;
        }
        return j;
    }
};
