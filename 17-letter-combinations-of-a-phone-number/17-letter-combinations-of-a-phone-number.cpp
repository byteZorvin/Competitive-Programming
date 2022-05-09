class Solution {
    void helper(string digits, int i, string &curr, vector<string>&ans) {
        if(i==digits.size()) {
            if(curr.size())
                ans.push_back(curr);
            return;
        }
        if(digits[i] == '9') {
            for(auto  c = 'w'; c<='z'; c++) {
                curr += c;
                helper(digits, i+1, curr, ans);
                curr.pop_back();
            }
        }
        else if (digits[i] == '7') {
            for(auto  c = 'p'; c<='s'; c++) {
                curr += c;
                helper(digits, i+1, curr, ans);
                curr.pop_back();
            }
        }
        else {
            int x = (digits[i] - '2')*3;
            if((digits[i] - '0') == 8) 
                x++;
            cout << x;
            for(char c = 'a' + x; c<'a' + x + 3; c++)  {
                curr += c;
                helper(digits, i+1, curr, ans);
                curr.pop_back();
            }
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr;
        helper(digits, 0, curr, ans);
        return ans;
    }
};