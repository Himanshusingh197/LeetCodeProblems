#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& nums1, vector<int>& nums2){
    vector<int> merged;
    int i = 0, j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] < nums2[j]) {
            merged.push_back(nums1[i]);
            i++;
        } else {
            merged.push_back(nums2[j]);
            j++;
        }
    }

    while (i < nums1.size()) {
        merged.push_back(nums1[i]);
        i++;
    }

    while (j < nums2.size()) {
        merged.push_back(nums2[j]);
        j++;
    }
    sort(merged.begin(), merged.end());
    int n = merged.size();
    if (n % 2 == 0) {
        return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    } else {
        return merged[n / 2];
    }
}

int main(){
    vector<int> nums1 = {5, 4};
    vector<int> nums2 = {6, 7};

    double median = findMedian(nums1, nums2);
    cout << "The median is: " << median << endl;

    return 0;
}