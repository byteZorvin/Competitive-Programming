class Solution {
public:
    vector<int> partitionLabels(string s) {
        int ch[26] = {0};
        int n = s.size();
        for(int i = 0; i<n; i++) ch[s[i] - 'a'] = i;
        
        vector<int> parts;
        int i = 0, j = 0; 
        while(i<n) {
            int endOfPart = ch[s[i] - 'a'];
            while(i<=endOfPart) {
                endOfPart = max(endOfPart, ch[s[i] - 'a']);
                i++;
            }
            parts.push_back(i-j);
            j = i;
        }
        return parts;
    }
};