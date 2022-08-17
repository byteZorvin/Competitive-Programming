class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> encoding = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> uniqueCodes;
        for(auto w: words) {
            string code;
            for(auto c: w) {
                code += encoding[c - 'a'];
            }
            uniqueCodes.insert(code);
        }
        return uniqueCodes.size();
    }
};