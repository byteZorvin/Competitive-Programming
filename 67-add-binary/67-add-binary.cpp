class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size()-1, j = b.size()-1, carry = 0;
        while(i>=0 or j>=0 or carry) {
            int sum = carry;
            if(i>=0) sum += a[i--] - '0';
            if(j>=0) sum += b[j--] - '0';
            int sum_final = (sum%2);
            ans += sum_final + '0';
            carry = (sum-sum_final)/2;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};