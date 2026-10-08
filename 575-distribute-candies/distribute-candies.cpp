class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> st;
        for(auto candy : candyType){
            st.insert(candy);
        }
        int n = st.size();
        int half = candyType.size() / 2;

        return min(half, n);
    }
};