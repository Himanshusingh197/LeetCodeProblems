class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;

        for(int i=0; i <= rowIndex; i++){
            ans.push_back(vector<int>(i + 1));

            for(int j=0; j <= i; j++){
                if(j == 0 || j == i){
                    ans[i][j] = 1;
                }
                else{
                    ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
                }
            }
        }
        return ans[rowIndex];
    }
};