class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>index;
        stack<char>chars;
        index.push(-1); 
        
        int ans = 0;
        
        for(int i = 0; i<s.size(); i++) {
            if(s[i] == '(' || chars.empty()) {
                index.push(i);
                chars.push(s[i]);
            }
            else if(chars.top() == '(') {
                chars.pop();
                index.pop();
                ans = max(ans, i - index.top());
            }
            else {
                index.push(i);
            }
        }
        return ans;
    }
};