class Solution {
public:
    bool isRobotBounded(string instructions) {
        int dir = 0;
        vector<int> distance(4, 0); // indexes will store distance covered in +y, +x, -y, -x (0, 1, 2, 3)
        for(char c : instructions) {
            switch(c) {
                case 'G' :
                    distance[dir]++;
                    break;
                case 'L' :
                    dir = (dir+3)%4;
                    break;
                case 'R' :
                    dir = (dir+1)%4;
                    break;
            }
        }
        int x = distance[1] - distance[3];
        int y = distance[0] - distance[2];
        
        if(dir==0) {
            if(x==0 and y==0) return true;
            return false;
        }
        return true;
    }
};