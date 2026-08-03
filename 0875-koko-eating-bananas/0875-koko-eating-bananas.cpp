class Solution {
public:
    long long reqTime(vector<int>& piles, int n){
        long long time = 0;
        for(int i=0; i<piles.size(); i++){
            time += ceil((double)piles[i] / (double)n);
        }
        return time;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = low + (high - low) / 2;
            long long timeTaken = reqTime(piles, mid);

            if(timeTaken <= h) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
