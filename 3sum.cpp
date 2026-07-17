#include<bits/stdc++.h>
using namespace std;


//1st approach: using 3 nested loops
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();
//         vector<vector<int>> ans;

//         set<vector<int>> s;       //set of unique triplets
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n;j++){
//                 for(int k=j+1; k<n; k++){
//                     if(nums[i] + nums[j] + nums[k] == 0){
//                         vector<int> trip = {nums[i], nums[j], nums[k]};
//                         sort(trip.begin(), trip.end());

//                         if(s.find(trip) == s.end()){
//                             s.insert(trip);
//                             ans.push_back(trip);
//                         }
//                     }
//                 }
//             }
//         }
//         return ans;
//     }
// };


//2nd approach: using 2 nested loops and a set
// class Solution {
// public:
//     vector<vector<int>> threeSum(vector<int>& nums) {
//         int n = nums.size();

//         set<vector<int>> uniqueTriplets;
//         for(int i=0; i<n; i++){
//             int target = -nums[i];
//             set<int> s;

//             for(int j=i+1; j<n; j++){
//                 int third = target - nums[j];

//                 if(s.find(third) != s.end()){
//                     vector<int> trip = {nums[i], nums[j], third};
//                     sort(trip.begin(), trip.end());
//                     uniqueTriplets.insert(trip);
//                 }
//                 s.insert(nums[j]);
//             }
//         }
        
//         vector<vector<int>> ans(uniqueTriplets.begin(), uniqueTriplets.end());
//         return ans;
//     }
// };


//3rd approach: using sorting and 2 pointers
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n - 2; i++){
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            
            int left = i + 1, right = n - 1;
            int target = -nums[i];
            
            while(left < right){
                int sum = nums[left] + nums[right];
                if(sum == target){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    while(left < right && nums[left] == nums[left+1]) left++;
                    while(left < right && nums[right] == nums[right-1]) right--;
                    left++;
                    right--;
                } else if(sum < target){
                    left++;
                } else {
                    right--;
                }
            }
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4};
    vector<vector<int>> ans = s.threeSum(nums);

    for(auto triplet: ans){
        for(auto num: triplet){
            cout << num << " ";
        }
        cout << endl;
    }
}