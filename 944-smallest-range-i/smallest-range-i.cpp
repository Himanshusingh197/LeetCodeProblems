class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minEl = nums[0];
        int maxEl = nums[0];

        for(int i = 1; i < nums.size(); i++) {
            minEl = min(minEl, nums[i]);
            maxEl = max(maxEl, nums[i]);
        }

        return max(0, maxEl - minEl - 2 * k);
    }
};