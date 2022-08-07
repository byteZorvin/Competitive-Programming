class Solution {
public:
    int fib(int n) {
        if (n==0) return 0;
        int a = 0, b = 1, c;
        while(n-->1) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};