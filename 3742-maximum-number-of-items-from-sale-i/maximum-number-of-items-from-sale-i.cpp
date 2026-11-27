class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // Step 1: Calculate contribution of each item
        vector<int> weight(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (i != j &&
                    items[j][0] % items[i][0] == 0) {

                    weight[i]++;
                }
            }
        }

        // Step 2: Sort items by price in descending order
        vector<int> order(n);

        for (int i = 0; i < n; i++) {
            order[i] = i;
        }

        sort(order.begin(), order.end(),
             [&](int a, int b) {
                 return items[a][1] > items[b][1];
             });

        const int NEG = -1000000000;

        // dp[c] = maximum contribution with exact cost c
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        int ans = 0;

        // Step 3: Process items grouped by price
        int i = 0;

        while (i < n) {

            int price = items[order[i]][1];

            // At least one item of current price must be selected
            vector<int> flag(budget + 1, NEG);

            while (i < n && items[order[i]][1] == price) {

                int idx = order[i];
                int w = weight[idx];

                for (int c = budget; c >= price; c--) {

                    if (dp[c - price] != NEG) {

                        flag[c] = max(
                            flag[c],
                            dp[c - price] + w
                        );
                    }

                    dp[c] = max(
                        dp[c],
                        dp[c - price] + w
                    );
                }

                i++;
            }

            // Step 4: Calculate answer for this minimum price
            for (int c = 0; c <= budget; c++) {

                if (flag[c] != NEG) {

                    int extra = (budget - c) / price;

                    ans = max(ans, flag[c] + extra);
                }
            }
        }

        return ans;
    }
};
