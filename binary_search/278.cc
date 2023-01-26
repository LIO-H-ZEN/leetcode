// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int bs(int64_t st, int64_t ed) {
        int64_t mid = (st + ed) / 2;
        bool flag = isBadVersion(mid);
        if (flag && mid == 1) {
            return 1; 
        } else if (flag && mid > 1 && !isBadVersion(mid-1)) {
            return mid;
        } else if (!flag) {
            return bs(mid, ed);
        } else {
            return bs(st, mid);
        }
    }
    int64_t firstBadVersion(int n) {
        return bs(1, (int64_t)n+1);
    }
};
