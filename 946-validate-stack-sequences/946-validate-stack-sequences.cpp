class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0, n = pushed.size();
        stack<int> st;

        while(i<n && j<n) {
            if(st.empty() || st.top() != popped[j]) st.push(pushed[i++]);
            else st.pop(), j++;
        }
        while(j<n && st.top() == popped[j]) {
            st.pop(), j++;
        }
        return j==n;
    }
};