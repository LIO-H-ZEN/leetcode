class Solution {
public:
    int binary_search(int st, int ed, vector<int>& nums, int target) {
        int mid = (st+ed)/2;
        if (nums[mid] == target) {
            return mid;
        } else if (st == ed || st + 1 == ed) {
            return -1;
        } else if (nums[mid] < target) {
            return binary_search(mid, ed, nums, target);
        } else {
            return binary_search(st, mid, nums, target);
        }
    }
    int search(vector<int>& nums, int target) {
        return binary_search(0, nums.size(), nums, target);
    }
};
