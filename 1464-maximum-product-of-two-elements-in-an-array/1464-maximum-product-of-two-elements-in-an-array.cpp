class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int max1 = 0, max2 = 0;
        priority_queue<int> pq(nums.begin(), nums.end());
        max1 = pq.top(); pq.pop();
        max2 = pq.top(); pq.pop();

        return (max1-1)*(max2-1);
    }
};