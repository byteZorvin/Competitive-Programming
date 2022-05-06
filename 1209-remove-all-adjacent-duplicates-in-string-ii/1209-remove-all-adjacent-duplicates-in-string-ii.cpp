class Solution {
public:
    string removeDuplicates(string s, int k) {
        int i = 0, n = s.size();
        vector<int> count(n);
        for(int j = 0; j<n; ++j, ++i) {
            s[i] = s[j];
            count[i] = i>0 && s[j] == s[i-1] ? count[i-1] + 1 : 1;
            if(count[i] == k)
                i -= k;
        }
        return s.substr(0, i);
    }
};