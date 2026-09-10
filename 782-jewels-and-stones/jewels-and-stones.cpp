class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count[128] = {0};

        for(char ch : jewels) {
            count[ch] = 1;
        }

        int ans = 0;
        for(char ch : stones) {
            if(count[ch] == 1) {
                ans++;
            }
        }

        return ans;
    }
};