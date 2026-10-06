class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans;

        if(n == 1){
            return {1};
        }

        vector<int> temp = beautifulArray((n+1) / 2);
        for(auto x : temp){
            int odd = 2 * x - 1;
            
            if(odd <= n){
                ans.push_back(odd);
            }
        }

        temp = beautifulArray(n/2);
        for(auto x : temp){
            int even = 2*x;

            if(even <= n){
                ans.push_back(even);
            }
        }
        return ans;
    }
};