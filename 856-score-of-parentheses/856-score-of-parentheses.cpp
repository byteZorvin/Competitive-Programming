class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        int cur = 0;
        for(auto &c: s) {
            if(c == '(') {
                st.push(cur);
                cur = 0;
            }
            else {
                cur = st.top() + max(cur*2, 1);
                st.pop();
            }
        }
        return cur;
    }
};