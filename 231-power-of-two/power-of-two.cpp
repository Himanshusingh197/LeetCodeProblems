class Solution {
public:
    bool isPowerOfTwo(int n) {

        long long x = 1;

        while(x < n) {
            x = x * 2;
        }

        return x == n;
    }
};