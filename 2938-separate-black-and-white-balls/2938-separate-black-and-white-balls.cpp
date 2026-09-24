class Solution {
public:
    long long minimumSteps(string s) {
        long long ans = 0;
        int i=0, j=0, n = s.size();

        int low = 0;

        for(int mid = 0; mid < n; mid++){
            if(s[mid] == '0'){
                swap(s[mid], s[low]);
                ans += mid - low;
                low++;
            }
        }

        // i for black ball , j for white ball
        // int firstBlack = -1, lastWhite = -1;

        // for(int i=n-1; i>=0; i--){
        //     if(s[i] == '0') {
        //         lastWhite = i;
        //         break;
        //     }
        // }

        // for(int i=0; i<n; i++){
        //     if(s[i] == '1'){
        //         firstBlack = i;
        //         break;
        //     }
        // }

        // if(lastWhite < firstBlack){
        //     return 0;
        // }

        

        return ans;      

    }
};