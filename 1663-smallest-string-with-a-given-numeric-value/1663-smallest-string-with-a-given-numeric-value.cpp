class Solution {
public:
    string getSmallestString(int n, int k) {
        string s(n, 'a');
        k -= n;
        while(k>0) {
            s[--n] += min(k, 25);
            k -= min(k, 25);
        }
        return s;
    }
};