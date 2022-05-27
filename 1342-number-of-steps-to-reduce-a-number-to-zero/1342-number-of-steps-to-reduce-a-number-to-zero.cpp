class Solution {
public:
    int numberOfSteps(int num) {
        return num == 0 ? 0 : sizeof(num)*8 - __builtin_clz(num) + __builtin_popcount(num) -1;
    }
};