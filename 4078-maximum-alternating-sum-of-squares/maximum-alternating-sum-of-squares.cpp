
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<long long> squares;

        for (int num : nums) {
            squares.push_back(1LL * num * num);
        }

        sort(squares.begin(), squares.end());

        long long score = 0;
        int n = squares.size();

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                score += squares[n - 1 - i / 2];
            } else {
                score -= squares[i / 2];
            }
        }

        return score;
    }
};
