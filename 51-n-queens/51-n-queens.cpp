class Solution {
private:
    bool isSafe(int row, int col, vector<string>&board) {
        for(int i = 0; i<col; i++) {
            if(board[row][i] == 'Q') return false;
        }
        for(int i = row, j = col; i<board.size() && j>=0; i++, j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row, j = col; i>=0 && j>=0; i--, j--) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
private:
    void solveUtil(int col, vector<vector<string>> &sol, vector<string> &board) {
        if(col==board.size()) {
            sol.push_back(board);
            return;
        }
        for(int i = 0; i<board.size(); i++) {
            if(isSafe(i, col, board)) {
                board[i][col] = 'Q';
                (solveUtil(col+1, sol, board));
                board[i][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> board(n, string(n, '.'));
        solveUtil(0, sol, board);
        return sol;
    }
};