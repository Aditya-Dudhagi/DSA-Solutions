class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans1=0, ans2 = 0;
        bool found = false;
        int n = words.size();
        for(int i=0; i<n; i++){
            if(words[(startIndex+i)%n] == target){
                found = true;
                break;
            }
            ans1++;
        }

        for(int i=0; i<n; i++){
            if(words[(startIndex-i+n)%n] == target){
                found = true;
                break;
            }
            ans2++;
        }
        return found ? min(ans1, ans2) : -1;
    }
};