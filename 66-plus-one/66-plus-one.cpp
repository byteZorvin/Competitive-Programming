class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        int carry = (digits[0]+1)/10;
        digits[0] = (digits[0]+1)%10;
        for(int i = 1; i<digits.size(); i++) {
            int newCarry = (digits[i] + carry)/10;
            digits[i] = (digits[i] + carry)%10;
            carry = newCarry;
        }
        if(carry)
            digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};