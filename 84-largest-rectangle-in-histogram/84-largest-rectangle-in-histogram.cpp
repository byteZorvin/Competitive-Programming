class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        
        for(int i = 0; i<n; i++) {
            while(!st.empty() && heights[i] <= heights[st.top()]) {
                int ind = st.top();
                st.pop();
                int currArea = heights[ind]*(st.empty() ? i : i - st.top() - 1);
                maxArea = max(maxArea, currArea);
            }
            st.push(i);
        }
        
        while(!st.empty()) {
            int ind = st.top();
            st.pop();
            int currArea = heights[ind]*(st.empty() ? n : n - st.top() - 1);
            maxArea = max(maxArea, currArea);
        }
        return maxArea;
    }
};