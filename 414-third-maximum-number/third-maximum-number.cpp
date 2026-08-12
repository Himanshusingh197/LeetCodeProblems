class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();

        long long firstMax = LLONG_MIN;
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;

        for (int i = 0; i < n; i++) {

            long long current = nums[i];

            // Ignore duplicate values
            if (current == firstMax ||
                current == secondMax ||
                current == thirdMax) {
                continue;
            }

            if (current > firstMax) {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = current;
            }
            else if (current > secondMax) {
                thirdMax = secondMax;
                secondMax = current;
            }
            else if (current > thirdMax) {
                thirdMax = current;
            }
        }

        if (thirdMax == LLONG_MIN) {
            return firstMax;
        }

        return thirdMax;
    }
};