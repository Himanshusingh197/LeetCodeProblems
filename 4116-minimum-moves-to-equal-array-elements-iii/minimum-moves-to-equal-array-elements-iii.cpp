class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        int maxEl = INT_MIN;

        for(int i=0; i<n; i++){
            maxEl = max(maxEl, nums[i]);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            while(nums[i] != maxEl){
                nums[i]++;
                count++;
            }
        }
        return count;
    }
};