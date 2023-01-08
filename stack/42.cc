class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() == 1) { return 0; }
        std::stack<int> st;
        int ret = 0, left_top = 0;
        for (int i = 0; i < height.size(); ++i) {
            while (!st.empty() && height[i] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) {
                    break;
                }
                int left = st.top();
                int w = i - left - 1; // i代表右端点，left代表左端点
                int h =std::min(height[i], height[left]) - height[top];
                ret += w*h;
            }
            st.push(i);
        }
        return ret;
    }
};
