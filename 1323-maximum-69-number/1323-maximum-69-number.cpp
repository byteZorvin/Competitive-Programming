class Solution {
public:
    int maximum69Number (int num) {
        string numString = to_string(num);
        int sixIndex = -1, i = 0;
        while(i<numString.size()) {
            if(numString[i] == '6') {
                sixIndex = i;
                break;
            }
            i++;
        }
        if(sixIndex != -1)
            numString[sixIndex] = '9';
        return stoi(numString);
    }
};