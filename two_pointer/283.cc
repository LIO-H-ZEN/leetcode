class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int st = 0;
        // 找到第一个0
        for (; st < nums.size(); ++st) {
            if (nums[st] == 0) {
                break;
            }
        }
        if (st == nums.size()-1) {
            // 没有0
            return ;
        }
        int ed = st + 1;
        while (ed < nums.size()) {
            if (nums[ed] == 0) {
                ++ed;
            } else {
                // 找到st之后第一个非0
                std::swap(nums[st], nums[ed]); // 每次都是第一个0和其之后的第一个非0交换
                // 将st置到第一个0的位置
                while (nums[st] != 0) {
                    ++st;
                }
            }
        }
    }
};
