class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> prefix;
        for(int i=0; i<arr1.size(); i++){
            string num = to_string(arr1[i]);
            string pre = "";
            for(char ch:num){
                pre += ch;
                prefix[pre]++;
            }
        }

        int maxlen = 0;
        for(int i=0; i<arr2.size(); i++){
            string num = to_string(arr2[i]);
            string pre = "";
            for(char ch:num){
                pre+=ch;
                if(prefix.find(pre) != prefix.end()){
                    maxlen = max(maxlen, (int)pre.length());
                }
            }
        }
        return maxlen;
    }
};