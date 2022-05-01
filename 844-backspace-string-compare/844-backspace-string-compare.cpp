class Solution {
    void fillStack(string &s, stack<char>&st) {
        for(auto &c: s) {
            if(c == '#') {
                if(!st.empty()) st.pop();
            } 
            else st.push(c);
        }
    }
    bool check(stack<char> &st, stack<char> &tt) {
        while(!tt.empty() && !st.empty()) {
            if(tt.top()!=st.top()) return false;
            tt.pop(); st.pop();
        }
        return tt.empty() && st.empty();
    }
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st, tt;
        fillStack(s, st);
        fillStack(t, tt);
        return check(st, tt);
    }
};