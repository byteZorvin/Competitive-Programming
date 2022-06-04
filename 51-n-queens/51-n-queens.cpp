class Solution {
    bool validCol(vector<string>&board, int currCol, int n) {
        for(int i = 0; i<n; i++)
            if(board[i][currCol] == 'Q') 
                return false;
        return true;
    }
    
    bool validDiag(vector<string>&board, int currRow, int currCol, int n) {
        int i = currRow, j = currCol;
        while(i>=0 && j>=0) {
            if(board[i][j] == 'Q')
                return false;
            i--, j--;
        }
        i = currRow, j = currCol;
        while(i>=0 && j<n) {
            if(board[i][j] == 'Q')
                return false;
            i--, j++;
        }
        return true;
    }
    
    bool Valid(vector<string>&board, int currRow, int currCol, int n) {
        return validCol(board, currCol, n) && validDiag(board, currRow, currCol, n);
    }
    
    void solve(vector<string>&board, int currRow, int n, vector<vector<string>>&solutions) {
        if(currRow == n) {
            solutions.push_back(board);
            return;
        }
        for(int i = 0; i<n; i++) {
            if(Valid(board, currRow, i, n)) {
                board[currRow][i] = 'Q';
                solve(board, currRow+1, n, solutions);
                board[currRow][i] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>solutions;
        vector<string>board(n, string(n, '.'));
        solve(board, 0, n, solutions);
        return solutions;
    }
};