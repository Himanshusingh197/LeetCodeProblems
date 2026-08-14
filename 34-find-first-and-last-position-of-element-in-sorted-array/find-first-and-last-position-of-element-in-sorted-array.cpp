class Solution {
public:
int first(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() -1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == target){
            ans = mid;
            high = mid -1;
        }else if(nums[mid] > target){
            high = mid -1;

        }else{
            low = mid +1;
        }
    }
    return ans;
}
int last(vector<int>& nums, int target){
    int low = 0;
    int high = nums.size() -1;
    int ans = -1;
    while(low <= high){
        int mid = (low + high)/2;
        if(nums[mid] == target){
            ans = mid;
            low = mid +1;
        }else if(nums[mid] > target){
            high = mid -1;

        }else{
            low = mid +1;
        }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
       int f = first(nums,target);
       if(f == -1){
        return {-1,-1};
       }
       int l = last(nums,target);
       return {f,l};
    }
};