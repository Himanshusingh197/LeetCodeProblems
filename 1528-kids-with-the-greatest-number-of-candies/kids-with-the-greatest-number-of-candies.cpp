class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxm = 0;
        for(int c : candies){
            maxm = max(maxm, c);
        }

        vector<bool> result;
        for(int c : candies){
            result.push_back(c + extraCandies >= maxm);
        } 
        return result;
    }
};