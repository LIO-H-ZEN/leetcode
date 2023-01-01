class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ret(digits.size());
        int plus = 1;
        for (int i = digits.size()-1; i >= 0; --i) {
            ret[i] = ((digits[i] + plus) % 10);
            plus = (digits[i] + plus) / 10;
        }
        if (plus > 0) {
            ret.insert(ret.begin(), 1);
        }
        return ret;
    }
};
