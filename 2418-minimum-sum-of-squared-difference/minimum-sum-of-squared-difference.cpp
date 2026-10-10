
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int maxi = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        int left = 0, right = maxi;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid) {
                    need += d - mid;
                }
            }

            if (need <= k)
                right = mid;
            else
                left = mid + 1;
        }

        int level = left;
        long long used = 0;

        for (int i = 0; i < n; i++) {
            if (diff[i] > level) {
                used += diff[i] - level;
                diff[i] = level;
            }
        }

        k -= used;

        for (int i = 0; i < n && k > 0; i++) {
            if (diff[i] == level && level > 0) {
                diff[i]--;
                k--;
            }
        }

        long long ans = 0;

        for (int d : diff) {
            ans += 1LL * d * d;
        }

        return ans;
    }
};
