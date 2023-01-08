class Solution {
public:
    string removeKdigits(string num, int k) {
        std::stack<int> st;
        unordered_map<int, int> dct;
        bool flag = true;
        int kk = k;
        for (int i = 0; i < num.size(); ++i) {
            while (!st.empty() && num[i] < num[st.top()]) {
                dct[st.top()] = 1;
                st.pop();
                --k;
                if (k == 0) {
                    flag = false;
                    break;
                }
            }
            if (!flag) break;
            st.push(i);
        }
        while (dct.size() != kk) {
            dct[st.top()] = 1;
            st.pop();
        }
        std::string ret = "";
        for (int i = 0; i < num.size(); ++i) {
            if (dct.find(i) == dct.end()) {
                ret += num[i];
            }
        }
        int i = 0;
        for (; i < ret.size(); ++i) {
            if (ret[i] != '0') break;
        }
        if (ret.substr(i) == "") {
            return "0";
        } else {
            return ret.substr(i);
        }
    }
};
