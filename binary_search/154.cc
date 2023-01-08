class Solution {
public:
    int binarySearch(int st, int ed, vector<int>& nums, int ed2) {
        int mid = (st + ed) / 2;;
        if (mid == 0 && nums[0] <= nums[1]) {
            return nums[mid];
        } else if (mid == ed2 && nums[mid] <= nums[mid-1]) {
            return nums[mid];
        } else if (mid > 0 && nums[mid] < nums[mid-1] && mid < ed2 && nums[mid] <= nums[mid+1]) {
            return nums[mid];
        } else if (nums[mid] <= nums[ed2]) {
            return binarySearch(st, mid, nums, ed2);
        } else {
            return binarySearch(mid, ed, nums, ed2);
        }
    }
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        if (nums.size() == 2) {return std::min(nums[0], nums[1]);}
        int i = 0, j = nums.size()-1;
        while (nums[i] == nums[j] && i != j) {
            --j;
        }
        if (i == j) {return nums[i];}
        return binarySearch(0, j+1, nums, j);
    }
};
