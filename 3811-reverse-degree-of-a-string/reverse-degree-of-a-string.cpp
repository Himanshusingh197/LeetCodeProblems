class Solution {
public:
    int reverseDegree(string s) {
        int n = s.length();

        int sum = 0;
        for(int i=0; i<n; i++){
            int reverseAlphabetPos = 'z' - s[i] + 1;
            sum += reverseAlphabetPos * (i+1);
        }

        return sum;
    }
};