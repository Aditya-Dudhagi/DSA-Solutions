class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        string ans = "";

        while (i >= 0 || j >= 0 || carry) {
            int bit1 = (i >= 0) ? a[i] - '0' : 0;
            int bit2 = (j >= 0) ? b[j] - '0' : 0;

            i--; j--;

            int sum = bit1 ^ bit2 ^ carry;

            carry = (bit1 & bit2) | (carry & (bit1 ^ bit2));

            ans.push_back(sum + '0');
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};