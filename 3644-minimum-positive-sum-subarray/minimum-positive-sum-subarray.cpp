class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int ans = INT_MAX;

        for(int k = l; k <= r; k++) {
            int sum = 0;

            // First window
            for(int i = 0; i < k; i++) {
                sum += nums[i];
            }

            if(sum > 0)
                ans = min(ans, sum);

            // Sliding window
            for(int i = k; i < n; i++) {
                sum += nums[i];
                sum -= nums[i-k];

                if(sum > 0)
                    ans = min(ans, sum);
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};