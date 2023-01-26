class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ret = -1;
        while (true) {
            ret = nums[rand() % nums.size()]; // 随机一个数，由于过半众数的定义，时间复杂度的期望为O(n)
            int cnt = 0;
            for (const auto& n:nums) {
                if (n == ret) { ++cnt; }
            }
            if (cnt > nums.size()/2) {
                break;
            }
        }
        return ret;
    }
};
