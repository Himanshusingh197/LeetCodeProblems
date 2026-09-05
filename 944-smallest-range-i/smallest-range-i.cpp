class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int maxEl = *max_element(nums.begin(), nums.end());
        int minEl = *min_element(nums.begin(), nums.end());

        return max(0, maxEl - minEl - 2*k);
    }
};