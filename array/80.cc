class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pre_val = nums[0];
        int j = 1, k = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == pre_val) {
                // 没记过第二次的，打一下.
                if (k == 0) {
                    nums[j] = pre_val;
                    ++j;
                    ++k;
                }
                continue;
            }
            nums[j] = nums[i];
            pre_val = nums[i];
            ++j;
            k = 0;
        }
        return j;
    }
};
