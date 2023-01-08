class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> val2ans;
        std::stack<int> st;
        for (int i = nums2.size()-1; i >= 0; --i) {
            while (!st.empty() && nums2[i] >= st.top()) {
                st.pop();
            }
            val2ans[nums2[i]] = st.empty()?-1:st.top();
            st.push(nums2[i]);
        }
        for (int i = 0; i < nums1.size(); ++i) {
            if (val2ans.find(nums1[i]) != val2ans.end()) {
                nums1[i] = val2ans[nums1[i]];
            } else {
                nums1[i] = -1;
            }
        }
        return nums1;
    }
};
