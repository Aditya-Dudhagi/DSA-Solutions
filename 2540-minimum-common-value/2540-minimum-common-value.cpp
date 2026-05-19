class Solution {
public:
    int binary(int target, vector<int> &arr){
        int low = 0, high = arr.size()-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(arr[mid] == target) return target;
            else if(arr[mid]>target) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        for(int i:nums1){
            if(binary(i, nums2) != -1) return i;
        }
        return -1;
    }
};