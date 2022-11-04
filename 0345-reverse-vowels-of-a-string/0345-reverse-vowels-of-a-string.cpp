class Solution {
    bool isVowel(char c) {
        char cl = tolower(c);
        return cl == 'a' || cl == 'e' || cl == 'i' || cl == 'o' || cl == 'u';
    }
public:
    string reverseVowels(string s) {
        string vowels;
        for(auto c: s) {
            if(isVowel(c))
                vowels += c;
        }
        string ans;
        int j = vowels.size() - 1;
        if(j<0) return s;
        while(j>=0) {
            for(auto c: s) {
                if(!isVowel(c)) 
                    ans += c;
                else ans += vowels[j--];
            }
        }
        return ans;
    }
};