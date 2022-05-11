class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long absN = abs((long)n);
        while(absN) {
            if(absN % 2) 
                ans *= x;
            x *= x;
            absN >>= 1;
        }
        return n > 0 ? ans : 1/ans;
    }
};