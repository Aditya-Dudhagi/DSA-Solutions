class Solution {
public:
    int maxProduct(vector<string>& words) {
        int mask1 = 0, mask2 = 0;
        int ans = 0;
        vector<int> mask;
        for(int i=0; i<words.size(); i++){
            int tmp = 0;
            for(char ch: words[i]){
                tmp |= (1<<(ch-'a'));
            }
            mask.push_back(tmp);
        }
        for(int i=0; i<words.size(); i++){
            mask1 = mask[i];
            int size1 = words[i].size();
            for(int j=i+1; j<words.size(); j++){
                mask2 = mask[j];
                int size2 = words[j].size();
                if((mask1&mask2) == 0){
                    ans = max(ans, size1*size2);
                }
            }
        }
        return ans;
    }
};