class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int left = 0;
        int right = 0;
        int target = 0;
        int total = 0;
        int sum = 0;
        int maxLength = -1;

        for(int i=0; i<n; i++){
            total += nums[i];
        }

        target = total - x;
        for(int right=0; right<n; right++){
            sum += nums[right];

            while(left <= right && sum > target){
                    sum -= nums[left];
                    left++;
                }

            if(sum == target){
                int length = right - left + 1;
                maxLength = max(maxLength, length);
            }
        }

        if(maxLength == -1){
            return -1;
        }
        
        return n - maxLength;
    }
};