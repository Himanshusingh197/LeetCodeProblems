class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();

        vector<bool> used(n, false);
        int pair = 0;
        for(int i=0; i<n; i++){

            if(used[i]){
                continue;
            }

            for(int j=i+1; j<n; j++){
                if(!used[j] && nums[i] == nums[j]){
                    pair++;
                    used[i] = true;
                    used[j] = true;
                    break;
                }
            }
        }
        int remainingElement = n - (pair * 2);

        return {pair, remainingElement};
    }
};