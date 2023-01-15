class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;
        unordered_map<int, int> dct;
        for (int i = 0; i < nums1.size(); ++i) {
            if (dct.find(nums1[i]) == dct.end()) {
                dct[nums1[i]] = 1;
            } else {
                dct[nums1[i]] += 1;
            }
        }
        for (int j = 0; j < nums2.size(); ++j) {
            if (dct.find(nums2[j]) != dct.end() && dct[nums2[j]] > 0) {
                ret.push_back(nums2[j]);
                dct[nums2[j]] -= 1;
            }
        }
        return ret;
    }
};
