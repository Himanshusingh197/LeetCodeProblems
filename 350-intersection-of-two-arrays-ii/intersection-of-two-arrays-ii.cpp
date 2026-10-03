class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        unordered_map<int, int> mp;
        for(int i=0; i<m; i++){
            mp[nums1[i]]++;
        }

        vector<int> result;
        for(int i=0; i<n; i++){
            if(mp.find(nums2[i]) != mp.end()){
                if(mp[nums2[i]] > 0){
                    result.push_back(nums2[i]);
                }
                mp[nums2[i]]--;
            }
        }
        return result;
    }
};