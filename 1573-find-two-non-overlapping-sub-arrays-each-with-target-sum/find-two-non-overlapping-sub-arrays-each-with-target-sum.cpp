class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        // best[i] = minimum length of a valid subarray
        // completely inside indices [0...i]
        vector<int> best(n, INT_MAX);

        unordered_map<int, int> mp;

        // prefix sum 0 exists before the array starts
        mp[0] = -1;

        int prefixSum = 0;
        int ans = INT_MAX;
        int minLength = INT_MAX;

        for (int i = 0; i < n; i++) {
            prefixSum += arr[i];

            // Copy previous best answer
            if (i > 0) {
                best[i] = best[i - 1];
            }

            // We need this prefix sum
            int required = prefixSum - target;

            // Check whether a previous prefix sum exists
            if (mp.find(required) != mp.end()) {
                int start = mp[required] + 1;
                int length = i - mp[required];

                // We already have a valid subarray before this one
                if (start > 0 && best[start - 1] != INT_MAX) {
                    ans = min(ans, length + best[start - 1]);
                }

                // Update shortest valid subarray
                minLength = min(minLength, length);
                best[i] = min(best[i], minLength);
            }

            // Store prefix sum and its latest index
            mp[prefixSum] = i;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};