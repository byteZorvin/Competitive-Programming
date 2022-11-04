class Solution {
    bool isVowel(char c) {
        char cl = tolower(c);
        return cl == 'a' || cl == 'e' || cl == 'i' || cl == 'o' || cl == 'u';
    }
public:
    string reverseVowels(string s) {
        int i = 0, j = s.size() - 1;
        while(i<j) {
            while(i<j && !isVowel(s[i])) i++;
            while(i<j && !isVowel(s[j])) j--;
            if(i<j) swap(s[i++], s[j--]);
        }
        return s;
    }
};