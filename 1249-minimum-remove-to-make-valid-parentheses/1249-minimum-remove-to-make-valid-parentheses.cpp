class Solution {
public:
    string minRemoveToMakeValid(string s) {
        vector<int> skip;
        stack<int> st;
        int n = s.size();
        for(int i = 0; i<n; i++) {
            if(s[i] == ')') {
                if(st.empty()) skip.push_back(i);
                else st.pop();
            }
            else if(s[i] == '(')st.push(i);
        }
        while(!st.empty()) {
            skip.push_back(st.top());
            st.pop();
        }
        sort(skip.begin(), skip.end());
        int j = 0;
        string ans;
        for(int i = 0; i<n; i++) {
            if(j<skip.size() && i==skip[j]) 
                j++;
            else ans += s[i];
        }
        return ans;
    }
};