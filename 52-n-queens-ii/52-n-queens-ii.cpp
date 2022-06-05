class Solution {
    bool validCol(vector<string> &board, int currCol) {
        int n = board.size();
        for(int i = 0; i<n; i++) {
            if(board[i][currCol] == 'Q')
                return false;
        }
        return true;
    }
    bool validDiag(vector<string> &board, int currRow, int currCol) {
        int n = board.size();
        int i = currRow, j = currCol;
        while(i>=0 && j>=0) {
            if(board[i][j] == 'Q') return false;
            i--, j--;
        }
        
        i = currRow, j = currCol;
        while(i>=0 && j<n) {
            if(board[i][j] == 'Q') return false;
            i--, j++;
        }
        
        return true;
    }
    
    bool Valid(vector<string> &board, int currRow, int currCol) {
        return validCol(board, currCol) && validDiag(board, currRow, currCol);
    }
    
    int solve(vector<string> &board, int currRow) {
        if(currRow == board.size()) 
            return 1;
        
        int count = 0;
        for(int j = 0; j<board.size(); j++) {
            if(Valid(board, currRow, j)) {
                board[currRow][j] = 'Q';
                count += solve(board, currRow+1);
                board[currRow][j] = '.';
            }
        }
        
        return count;
    }
public:
    int totalNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        return solve(board, 0);
    }
};