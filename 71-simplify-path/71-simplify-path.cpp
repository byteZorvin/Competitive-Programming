class Solution {
public:
    string simplifyPath(string path) {
        path.push_back('/');
        string temp;
        stack<string> st;
        for(auto &c: path) {
            if(c == '/') {
                if(temp == "..") {
                    if(!st.empty())
                        st.pop();
                }   
                else if(!temp.empty() && temp != ".") st.push(temp);
                temp = "";
            }
            else
                temp += c;
        }
        string ans;
        while(!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }
        if(ans.empty()) ans += "/";
        return ans;
    }
};