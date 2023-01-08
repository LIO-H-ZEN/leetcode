// 从左向右
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> st;
        unordered_map<int, int> dct;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                dct[st.top()] = i-st.top();
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < temperatures.size(); ++i) {
            temperatures[i] = dct[i];
        }
        return temperatures;
    }
};

// 从右向左
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        std::stack<int> st;
        unordered_map<int, int> dct;
        dct[temperatures.size()-1] = 0;
        st.push(temperatures.size()-1);
        for (int i = temperatures.size()-2; i >= 0; --i) {
            while (!st.empty() && temperatures[i] >= temperatures[st.top()]) {
                st.pop();
            }
            dct[i] = st.empty()?0:st.top()-i;
            st.push(i);
        }
        for (int i = 0; i < temperatures.size(); ++i) {
            temperatures[i] = dct[i];
        }
        return temperatures;
    }
};
