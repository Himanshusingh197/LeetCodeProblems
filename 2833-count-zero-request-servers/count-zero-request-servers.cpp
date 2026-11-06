class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs,
                             int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int q = queries.size();

        vector<pair<int, int>> sortedQueries;

        for (int i = 0; i < q; i++) {
            sortedQueries.push_back({queries[i], i});
        }

        sort(sortedQueries.begin(), sortedQueries.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(q);

        int left = 0, right = 0;
        int active = 0;

        for (auto &query : sortedQueries) {

            int time = query.first;
            int index = query.second;

            int start = time - x;

            // Add logs whose time is <= query time
            while (right < logs.size() && logs[right][1] <= time) {

                int server = logs[right][0];

                if (freq[server] == 0) {
                    active++;
                }

                freq[server]++;
                right++;
            }

            // Remove logs whose time is < start
            while (left < right && logs[left][1] < start) {

                int server = logs[left][0];

                freq[server]--;

                if (freq[server] == 0) {
                    active--;
                }

                left++;
            }

            ans[index] = n - active;
        }

        return ans;
    }
};