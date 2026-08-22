class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1 = 0, cnt2 = 0;
        int el1 = INT_MIN, el2 = INT_MIN;
        int n = nums.size();

        vector<int> ans;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && el2 != nums[i]){
                cnt1 = 1, el1 = nums[i];
            }
            else if(cnt2 == 0 && el1 != nums[i]){
                cnt2 = 1, el2 = nums[i];
            }
            else if(el1 == nums[i]) cnt1++;
            else if(el2 == nums[i]) cnt2++;
            else {
                cnt1--, cnt2--;
            }
        }

        cnt1 = 0, cnt2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == el1) cnt1++;
            if(nums[i] == el2) cnt2++;
        }

        int fre = (int)n/3 + 1;

        if(cnt1 >= fre) ans.push_back(el1);
        if(cnt2 >= fre) ans.push_back(el2);

        sort(ans.begin(), ans.end());
        
        return ans;
    }
};