class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size();

        int mid = n / 2, count = 0;
        for(int i=0; i<n; i++){
            if(nums[mid] == nums[i])
                count++;
        }
        if(count == 1)
            return true;
        else
            return false;
    }
};