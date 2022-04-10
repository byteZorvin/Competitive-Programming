class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(auto &c: ops) {
            if(c == "+") {
                int a = st.top(); st.pop();
                int b = st.top();
                st.push(a);
                st.push(a+b);
            }
            else if(c == "D") st.push(st.top()*2);
            else if(c == "C") st.pop();
            else st.push(stoi(c));
        }
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};