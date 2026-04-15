class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int ans1=0;
        bool found = false;
        int n = words.size();
        for(int i=0; i<n; i++){
            if(words[(startIndex+i)%n] == target || words[(startIndex-i+n)%n] == target){
                found = true;
                break;
            }
            ans1++;
        }

        return found ? ans1 : -1;
    }
};