class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int size = n / 2;
        vector<bool> prime(size, true);

        int limit = sqrt(n - 1);

        for (int i = 1; 2 * i + 1 <= limit; i++) {
            if (prime[i]) {
                int p = 2 * i + 1;
                int start = (p * p - 1) / 2;

                for (int j = start; j < size; j += p) {
                    prime[j] = false;
                }
            }
        }

        int count = 0;

        for (int i = 1; i < size; i++) {
            if (prime[i])
                count++;
        }

        return count + 1;
    }
};