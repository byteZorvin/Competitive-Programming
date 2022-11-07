class Solution {
public:
    int maximum69Number (int num) {
        string numString = to_string(num);
        int i = 0;
        while(i<numString.size()) {
            if(numString[i] == '6') {
                numString[i] = '9';
                break;
            }
            i++;
        }
        return stoi(numString);
    }
};