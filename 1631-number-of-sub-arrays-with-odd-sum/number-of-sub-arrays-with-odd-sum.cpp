class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int odd = 0;
        int even = 1;
        int prefixSum = 0;
        long long count = 0;

        int MOD = 1e9 + 7;

        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];

            if(prefixSum % 2 == 0) {
                count += odd;
                even++;
            }
            else {
                count += even;
                odd++;
            }

            count %= MOD;
        }

        return count;
    }
};