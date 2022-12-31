class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0, j = 0;
        while ( i < nums.size() ) {
            if (nums[i] != val) {
                nums[j] = nums[i];
                ++i;
                ++j;
            } else {
                while (i < nums.size() && nums[i] == val) {
                    ++i;
                }
                if (i < nums.size()) {
                    nums[j] = nums[i];
                    ++i;
                    ++j;
                }
            }
        }
        return j;
    }
};
