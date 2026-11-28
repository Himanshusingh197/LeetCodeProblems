
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // Step 1: Find minimum price
        long long minPrice = LLONG_MAX;

        vector<int> freq(n + 1, 0);

        for (auto &item : items) {
            minPrice = min(minPrice, (long long)item[1]);
            freq[item[0]]++;
        }

        // Step 2: Count items whose factors are multiples
        vector<int> divisible(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divisible[i] += freq[j];
            }
        }

        // Step 3: Calculate available free-copy opportunities
        vector<pair<long long, long long>> opportunities;

        for (auto &item : items) {

            int factor = item[0];
            long long price = item[1];

            // Exclude the item itself
            long long freeCount = divisible[factor] - 1;

            // Only consider useful opportunities
            if (freeCount > 0 && price <= 2 * minPrice) {
                opportunities.push_back({price, freeCount});
            }
        }

        // Step 4: Sort by price
        sort(opportunities.begin(), opportunities.end());

        // Step 5: Greedily purchase bonus copies
        long long remaining = budget;
        long long bonusCopies = 0;

        for (auto &[price, count] : opportunities) {

            long long take = min(count, remaining / price);

            bonusCopies += take;
            remaining -= take * price;
        }

        // Step 6: Purchase additional regular copies
        long long regularCopies = remaining / minPrice;

        return (int)(2 * bonusCopies + regularCopies);
    }
};
