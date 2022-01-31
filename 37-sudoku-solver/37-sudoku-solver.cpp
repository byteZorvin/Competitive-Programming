class Solution {
private:
    bool isSafe(int i, int j, char c, vector<vector<char>>&board) {
        for(int k = 0; k<9; k++) {
            if(board[k][j] == c || board[i][k] == c) 
                return false;
        }
        int rs = i - i%3, cs = j - j%3;
        for(int i = 0; i<3; i++) {
            for(int j = 0; j<3; j++) {
                if(board[i+rs][j+cs] == c) return false;
            }
        }
        return true;
    }
private:
    vector<int> findEmpty(vector<vector<char>>&baord) {
        for(int i = 0; i<9; i++) {
            for(int j = 0; j<9; j++) {
                if(baord[i][j] == '.') return {i, j};
            }
        }
        return {};
    }
public:
    bool solve(vector<vector<char>> &board) {
        vector<int> ind = findEmpty(board);
        int i, j;
        if(ind.empty()) return true;
        else
            i = ind[0], j = ind[1];
        for(char c = '1'; c<='9'; c++) {
            if(isSafe(i, j, c, board)) {
                board[i][j] = c;
                if(solve(board)) return true;
            }
            board[i][j] = '.';
        }
        return false;
    }

public:    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};