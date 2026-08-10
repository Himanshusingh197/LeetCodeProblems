class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i=0; i<n; i++){
            mp[nums[i]]++;
        }

        int degree = 0;
        for(auto x : mp) {
            degree = max(degree, x.second);
        }

        int ans = n;
        for(auto x : mp) {
            int number = x.first;
            int frequency = x.second;

            if(frequency == degree) {
                int first = -1;
                int last = -1;

                for(int i = 0; i < n; i++) {
                    if(nums[i] == number) {
                        if(first == -1) {
                            first = i;
                        }
                        last = i;
                    }
                }

                int length = last - first + 1;
                ans = min(ans, length);
            }
        }

        return ans;
    }
};