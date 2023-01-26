class Solution {
public:
    int bs(int st, int ed, vector<int>& nums, int target) {
        int mid = (st+ed) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (st == ed || st + 1 == ed) {
            if (ed == nums.size()) {
                ed = nums.size()-1;
            }
            if (nums[ed] < target) {
                return ed+1;
            } else if (nums[st] < target) {
                return st+1;
            } else {
                return st==0?0:st-1;
            }
        } else if (nums[mid] < target) {
            return bs(mid, ed, nums, target);
        } else {
            return bs(st, mid, nums, target);
        }
    }
    int searchInsert(vector<int>& nums, int target) {
        return bs(0, nums.size(), nums, target);
    }
};
