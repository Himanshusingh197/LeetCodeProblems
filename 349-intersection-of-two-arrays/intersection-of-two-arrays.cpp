class Solution {
public:

    bool binarySearch(vector<int>& nums, int target){
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = l + (r-l)/2;

            if(nums[mid] == target){
                return true;
            }else if(nums[mid] < target){
                l = mid + 1;
            }else{
                r = mid - 1;
            }
        }
        return false;
    }

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
       sort(nums1.begin(), nums1.end());
       unordered_set<int> st;

       for(int num : nums2){
        if(binarySearch(nums1, num)){
            st.insert(num);
        }
       }
       vector<int> ans(st.begin(), st.end());

        return ans;
    }
};