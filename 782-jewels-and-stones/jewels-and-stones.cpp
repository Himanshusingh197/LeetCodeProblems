class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;

        for(char ch : jewels) {
            mp[ch] = 1;
        }

        int count = 0;

        for(char ch : stones) {
            if(mp.find(ch) != mp.end()) {
                count++;
            }
        }

        return count;
    }
};