class Solution {
public:
    int binarySearch(int st, int ed, vector<int>& nums) {
        int mid = (st + ed) / 2;
        if ((mid == 0 && nums[0] < nums[1]) ||
             (mid == nums.size()-1 && nums[mid] < nums[mid-1])) {
            return nums[mid];
        } else if (mid > 0 && nums[mid] < nums[mid-1] && mid < nums.size()-1 && nums[mid] < nums[mid+1]){
            return nums[mid];
        } else if (nums[mid] > nums[nums.size()-1]) {
            return binarySearch(mid, ed, nums);
        } else {
            return binarySearch(st, mid, nums);
        }
    }
    int findMin(vector<int>& nums) {
        if (nums.size() == 1) {return nums[0];}
        return binarySearch(0, nums.size(), nums);
    }
};
