class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        vector<vector<int>> ans(2);
        for(int i=0; i<m; i++){
            if(find(nums2.begin(), nums2.end(), nums1[i]) == nums2.end()){
                if(find(ans[0].begin(), ans[0].end(), nums1[i]) == ans[0].end()){
                    ans[0].push_back(nums1[i]);
                }
            }
        }

        for(int i=0; i<n; i++){
            if(find(nums1.begin(), nums1.end(), nums2[i]) == nums1.end()){
                if(find(ans[1].begin(), ans[1].end(), nums2[i]) == ans[1].end()){
                    ans[1].push_back(nums2[i]);
                }
            }
        }

        return ans;
    }
};