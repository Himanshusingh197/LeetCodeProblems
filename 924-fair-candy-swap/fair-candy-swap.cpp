class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int m = aliceSizes.size();
        int n = bobSizes.size();

        int sum1 = 0;
        int sum2 = 0;

        for(int i=0; i<m; i++){
            sum1 += aliceSizes[i];
        }

        for(int i=0; i<n; i++){
            sum2 += bobSizes[i];
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int newAlice = sum1 - aliceSizes[i] + bobSizes[j];
                int newBob = sum2 - bobSizes[j] + aliceSizes[i];

                if(newAlice == newBob){
                    return {aliceSizes[i], bobSizes[j]};
                }
            }
        }

        return {};
    }
};