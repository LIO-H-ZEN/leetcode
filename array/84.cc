class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.size() == 1) {return heights[0];}
        int ret = 0;
        std::stack<int> st;
        /*
            前后补0
                1. 最后补0：保证全部都会弹栈.
                2. 首部补0：保证[2,1,2]中的1，可以计算到全体 (i.e., 3*1=3)
        */
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[st.top()] > heights[i]) {
                int top = heights[st.top()];
                st.pop();
                int last_top_idx = st.top(); // 求前面尚未弹栈的元素位置，中间跳过的元素说明是比top更大的值，所以，以此可计算高度为top的最大矩形面积.
                ret = std::max(ret, (i - last_top_idx - 1) * top);
            }
            st.push(i);
        }
        return ret;
    }
};
