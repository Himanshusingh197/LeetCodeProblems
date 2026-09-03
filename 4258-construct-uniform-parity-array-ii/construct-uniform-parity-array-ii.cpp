class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minimum = INT_MAX;
        
        for(auto x : nums1){
            minimum = min(minimum, x);
        }

        if(minimum % 2 == 1){
            return true;
        }

        for(auto x : nums1){
            if(x % 2 == 1){
                return false;
            }
        }
        return true;
    }
};