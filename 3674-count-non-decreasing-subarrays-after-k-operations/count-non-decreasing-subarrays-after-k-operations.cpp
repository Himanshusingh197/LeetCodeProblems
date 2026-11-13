
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), LOG = 20;

        vector<int> nxt(n, n), st;

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty()) nxt[i] = st.back();
            st.push_back(i);
        }

        vector<vector<int>> up(LOG, vector<int>(n, n));
        vector<vector<long long>> sum(LOG, vector<long long>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i < n; i++) {
                int p = up[j-1][i];
                up[j][i] = p < n ? up[j-1][p] : n;
                sum[j][i] = sum[j-1][i] + (p < n ? sum[j-1][p] : 0);
            }
        }

        vector<long long> pref(n+1, 0);
        for (int i = 0; i < n; i++)
            pref[i+1] = pref[i] + nums[i];

        auto cost = [&](int l, int r) {
            long long s = 0;
            int p = l;

            for (int j = LOG-1; j >= 0; j--) {
                if (up[j][p] <= r) {
                    s += sum[j][p];
                    p = up[j][p];
                }
            }

            return s + 1LL * nums[p] * (r-p+1)
                     - (pref[r+1] - pref[l]);
        };

        long long ans = 0;
        int l = 0;

        for (int r = 0; r < n; r++) {
            while (cost(l, r) > k)
                l++;

            ans += r - l + 1;
        }

        return ans;
    }
};
