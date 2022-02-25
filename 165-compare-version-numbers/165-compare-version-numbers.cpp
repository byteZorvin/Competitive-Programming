class Solution {
public:
    int compareVersion(string version1, string version2) {
        stringstream ss1(version1), ss2(version2);
        string a, b;
        while(true) {
            int first, second;
            if(!getline(ss1, a, '.')) first = 0;
            else first = stoi(a);
            if(!getline(ss2, b, '.')) second = 0;
            else second = stoi(b);
            if(first<second) 
                return -1;
            else if(second<first)
                return 1;
            if(!ss1 && !ss2) return 0;
        }
    }
};