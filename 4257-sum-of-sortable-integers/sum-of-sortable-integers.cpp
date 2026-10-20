class Solution {
public:
    bool canRotate(vector<int>& nums, vector<int>& sorted,
                   int start, int k) {
        vector<int> lps(k, 0);

        // Build the LPS array for the sorted group
        for (int i = 1, len = 0; i < k; ) {
            if (sorted[start + i] == sorted[start + len]) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        // Search for the sorted group in the doubled original group
        int i = 0, j = 0;

        while (i < 2 * k - 1) {
            int value = nums[start + i % k];

            if (value == sorted[start + j]) {
                i++;
                j++;

                if (j == k) {
                    return true;
                }
            } else if (j > 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) {
                continue;
            }

            bool sortable = true;

            for (int i = 0; i < n; i += k) {
                if (!canRotate(nums, sorted, i, k)) {
                    sortable = false;
                    break;
                }
            }

            if (sortable) {
                ans += k;
            }
        }

        return ans;
    }
};