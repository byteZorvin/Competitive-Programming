class Solution {
private:
    int addHelper(string s) {
        if(s.size() == 1) return (s[0] - '0');
        
        int sum = 0;
        for(auto &c: s) sum += (c - '0');
        
        return addHelper(to_string(sum));
    }
public:
    int addDigits(int num) {
        string s = to_string(num);
        return addHelper(s);
    }
};