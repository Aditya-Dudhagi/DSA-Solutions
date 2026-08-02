class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        long long ans = INT_MIN;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j) continue;
                long long gc = gcd(nums[i], nums[j]); 
                ans = max(ans, (((long long)nums[i]*(long long)nums[j]))/((long long)(gc * gc)));
            }
        }
        return ans;
    }
};