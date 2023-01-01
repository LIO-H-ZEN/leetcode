class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        for (; i < nums.size(); ++i) {
            if (nums[i] == val) {
                continue;
            }
            nums[j] = nums[i];
            ++j;
        }
        return j;
    }
};
