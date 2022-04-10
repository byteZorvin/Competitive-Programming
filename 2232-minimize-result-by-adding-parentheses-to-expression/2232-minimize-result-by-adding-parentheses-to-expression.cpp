class Solution {
public:
    string minimizeResult(string exp) {
        int maxi = -1;
        string ans;
        int plus = exp.find('+');
        for(int l = stoi(exp.substr(0, plus)), mul = 10; mul <= l*10; mul *= 10) {
            int a = l/mul, b = l%mul;
            for(int r = stoi(exp.substr(plus+1)), mul = 1; mul<=r; mul *= 10) {
                int c = r/mul, d = r%mul;
                if(maxi == -1 || max(a, 1)*(b+c)*max(d, 1) < maxi) {
                    maxi = max(a, 1)*(b+c)*max(d, 1);
                    ans.clear();
                    if(a) ans += to_string(a);
                    ans += '(';
                    ans += to_string(b);  
                    ans += '+';
                    ans += to_string(c);
                    ans += ')';
                    if(d) ans += to_string(d);
                }
            }
        }
        cout << maxi << endl;
        return ans;
    }
};