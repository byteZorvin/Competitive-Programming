class Solution {
public:
    string removeDuplicates(string s) {
        int i = 1;
        int n = s.size();
        for(int j = 1; j<n; j++) {
            if(i>0 && s[j] == s[i-1])
                i--;
            else s[i++] = s[j]; 
        }
        return s.substr(0, i);
    }
};