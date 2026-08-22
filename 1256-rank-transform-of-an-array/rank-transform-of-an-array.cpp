class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();

        
        int rank = 1;
        vector<int> temp = arr;
        unordered_map<int, int> mp;

        sort(temp.begin(), temp.end());
        for(int i=0; i<n; i++){
            if(i > 0 && temp[i] != temp[i-1]){
                rank++;
            }
            mp[temp[i]] = rank;
        }

        for(int i=0; i<n; i++){
            arr[i] = mp[arr[i]];
        }

        return arr;
    }
};