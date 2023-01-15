class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> dct = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        std::stack<char> st;
        for (int i = 0; i < s.size(); ++i) {
            if (st.empty()) {
                st.push(s[i]);
            } else if (dct.find(s[i]) != dct.end()) {
                st.push(s[i]);
            } else if (dct[st.top()] != s[i]) {
                return false;
            } else {
                st.pop();
            }
        }
        if (!st.empty()) {
            return false;
        }
        return true;
    }
};
