class Solution {
public:
    void reverseString(vector<char>& s) {
        int st = 0, ed = s.size()-1;
        while (st < ed) {
            std::swap(s[st], s[ed]);
            ++st;
            --ed;
        }
    }
};
