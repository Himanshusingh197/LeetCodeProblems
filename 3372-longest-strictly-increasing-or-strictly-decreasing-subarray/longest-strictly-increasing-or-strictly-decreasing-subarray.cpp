class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();

        int maxSub = 1;
        int incCount = 1;
        int decCount = 1;

        for(int i=1; i<n; i++){
            if(nums[i] > nums[i-1]){
                incCount++;
                decCount = 1;
            }
            else if(nums[i] < nums[i-1]){
                decCount++;
                incCount = 1;
            }
            else{
                incCount = 1;
                decCount = 1;
            }

            maxSub = max(maxSub, max(incCount, decCount));
        }

        return maxSub;
    }
};