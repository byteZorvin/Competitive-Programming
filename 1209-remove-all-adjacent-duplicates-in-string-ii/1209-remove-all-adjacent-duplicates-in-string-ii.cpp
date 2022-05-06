class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int, int>> st; 
        for(int i = 0; i<s.size(); ++i) {
            if(!st.empty() && s[st.top().first] == s[i]) {
                st.push({i, st.top().second + 1});
            }
            else 
                st.push({i, 1});
            if(st.top().second == k) {
                int x = k;
                while(x--) {
                    st.pop();
                }
            }
        }
        string ans;
        while(!st.empty()) {
            ans += s[st.top().first];
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};