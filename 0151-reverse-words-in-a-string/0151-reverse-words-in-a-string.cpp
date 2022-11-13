class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int k = 0;
        for(int i = 0; i<s.size(); i++) {
            if(s[i] != ' ') {
                if(k != 0) s[k++] = ' ';
                int j = i;
                while(j<s.size() && s[j] != ' ') s[k++] = s[j++];
                reverse(s.begin()+k-(j-i), s.begin()+k);
                i = j;  
            }
        }
        s.erase(s.begin()+k, s.end());
        return s;
    }
};