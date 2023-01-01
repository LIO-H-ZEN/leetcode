class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> dct;
        for (int i = 0; i < nums.size(); ++i) {
            dct[nums[i]] = i;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (dct.find(target - nums[i]) != dct.end() && dct[target - nums[i]] != i) {
                return {i, dct[target - nums[i]]};
            }
        }
        return {-1,-1};
    }
};
