class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(auto &c: num) {
            if(st.empty() || st.top()<=c) {
                st.push(c);
            }
            else {
                while(k && !st.empty() && st.top() > c) {
                    k--;
                    st.pop();
                }
                st.push(c);
            }
        }
        
        while(k) {
            k--;
            st.pop();
        }
        
        string s;
        int firstNonZero = st.size() - 1, index = st.size()-1;
        while(!st.empty()) {
            char c = st.top(); st.pop();
            if(c != '0') firstNonZero = index;
            s += c;
            index--;
        }
        if(s.empty()) return "0";
        reverse(s.begin(), s.end());
        return s.substr(firstNonZero);
    }
};