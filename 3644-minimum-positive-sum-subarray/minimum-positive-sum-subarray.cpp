class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int minSumSub = INT_MAX;

        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];

                int len = j - i + 1;

                if (sum > 0 && len >= l && len <= r) {
                    minSumSub = min(minSumSub, sum);
                }
            }
        }

        return minSumSub == INT_MAX ? -1 : minSumSub;
    }
};