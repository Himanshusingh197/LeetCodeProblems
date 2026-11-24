class Solution {
public:
    int findGCD(int a, int b) {
        if (b == 0)
            return a;

        return findGCD(b, a % b);
    }

    long long findLCM(long long a, long long b) {
        if (a == 0 || b == 0)
            return 0;

        long long g = findGCD(a, b);

        if (a / g > LLONG_MAX / b)
            return LLONG_MAX;

        return (a / g) * b;
    }

    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            long long prod = 1;
            int gcd = 0;
            long long lcm = 1;

            for (int j = i; j < n; j++) {

                if (prod > LLONG_MAX / nums[j])
                    break;
                prod *= nums[j];

                gcd = findGCD(gcd, nums[j]);
                lcm = findLCM(lcm, nums[j]);

                if (prod == gcd * lcm) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};