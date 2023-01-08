class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        if (nums.size() == 1) { return {-1}; }
        int maxn = -1e9, max_idx = -1;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] >= maxn) {
                maxn = nums[i];
                max_idx = i;
            }
        }
        int j = max_idx == 0?nums.size()-1:max_idx-1;
        std::stack<int> st;
        st.push(nums[max_idx]);
        unordered_map<int, int> dct;
        dct[max_idx] = -1;
        while (j != max_idx) {
            while (!st.empty() && nums[j] >= st.top()) {
                st.pop();
            }
            dct[j] = st.empty()?-1:st.top();
            st.push(nums[j]);
            --j;
            if (j < 0) {
                j = nums.size()-1;
            }
        }
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] = dct[i];
        }
        return nums;
    }
};
