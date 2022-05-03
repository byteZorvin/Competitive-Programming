class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        int l = n, r = 0;
        for(int i = 0; i<n; i++) {
            while(!st.empty() && nums[st.top()] > nums[i]) {
                l = min(l, st.top());
                st.pop();
            }
            st.push(i);
        }
        stack<int> st2;
        for(int i = n-1; i>=0; i--) {
            while(!st2.empty() && nums[st2.top()] < nums[i]) {
                r = max(r, st2.top());
                st2.pop();
            }
            st2.push(i);
        }
        return max(0, r - l + 1);
    }
};