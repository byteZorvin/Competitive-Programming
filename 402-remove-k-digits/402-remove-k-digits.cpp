class Solution {
public:
    string removeKdigits(string num, int k) {
        while(k) {
            int i = 0, n = num.size();
            for(i = 1; i<=n; i++) {
                if(i==n) {
                    k--;
                    num.pop_back();
                    break;
                } 
                else if(num[i] < num[i-1]) {
                    k--;
                    num = num.substr(0, i-1) + num.substr(i);
                    break;
                }
            }
        }
        int j = 0;
        while(num[j] == '0') {
            j++;
        }
        if(j == num.size()) return "0";
        return num.substr(j);
    }
};