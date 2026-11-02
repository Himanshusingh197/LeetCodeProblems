class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int median = nums[n / 2];

        long long sum = 0;

        for(int i = 0; i < n; i++) {
            sum += abs((long long)nums[i] - median);
        }

        return (int)sum;
    }
};