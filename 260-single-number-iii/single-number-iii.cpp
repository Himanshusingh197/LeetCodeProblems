class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long ans = 0;

        for(int val : nums){
            ans ^= val;
        }

        long long bit = ans & (-ans);

        int a = 0;
        int b = 0;
        for(int num : nums){
            if(num & bit){
                a ^= num;
            }
            else{
                b ^= num;
            }
        }

        return {a, b};
    }
};