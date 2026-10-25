class Solution {
public:
    long long countPairs(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        long long count = 0;

        while (left < right) {
            if (nums[left] + nums[right] <= target) {
                count += right - left;
                left++;
            } else {
                right--;
            }
        }

        return count;
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());

        return countPairs(nums, upper) -
               countPairs(nums, lower - 1);
    }
};