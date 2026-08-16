class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int n, int k, int start) {

        if (temp.size() == k) {
            ans.push_back(temp);
            return;
        }

        for (int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(n, k, i + 1);
            temp.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {

        solve(n, k, 1);
        return ans;
    }
};