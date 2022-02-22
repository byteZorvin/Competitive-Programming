class Solution {
public:
    int titleToNumber(string columnTitle) {
        int colNo = 0;
        for(auto &c: columnTitle) {
            colNo = colNo*26 + (c - 'A' + 1);
        }
        return colNo;
    }
};