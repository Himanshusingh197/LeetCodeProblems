class Solution {
public:
    string mergeCharacters(string s, int k) {

        while (true) {

            bool merged = false;

            for (int i = 0; i < s.size(); i++) {

                for (int j = i + 1; j < s.size(); j++) {

                    if (s[i] == s[j] && j - i <= k) {
                        
                        s = s.substr(0, j) + s.substr(j + 1);

                        merged = true;
                        break;
                    }
                }

                if (merged)
                    break;
            }

            if (!merged)
                break;
        }

        return s;
    }
};