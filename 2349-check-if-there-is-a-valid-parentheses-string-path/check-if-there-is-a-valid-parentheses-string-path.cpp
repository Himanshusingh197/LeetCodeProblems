class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if ((m + n - 1) % 2 == 1)
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m + n, false)));

        // Starting cell
        if (grid[0][0] == '(')
            dp[0][0][1] = true;
        else
            return false;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                // Skip starting cell
                if (i == 0 && j == 0)
                    continue;

                for (int balance = 0; balance <= m + n; balance++) {

                    int newBalance;

                    if (grid[i][j] == '(')
                        newBalance = balance + 1;
                    else
                        newBalance = balance - 1;

                    if (newBalance < 0)
                        continue;
\
                    if (i > 0 && dp[i - 1][j][balance])
                        dp[i][j][newBalance] = true;

                    if (j > 0 && dp[i][j - 1][balance])
                        dp[i][j][newBalance] = true;
                }
            }
        }

        return dp[m - 1][n - 1][0];
    }
};