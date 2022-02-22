class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++) {
            unordered_set<char> seenRow, seenCol;
            for(int j = 0; j<9; j++) {
                
                if(seenRow.count(board[i][j])) 
                    return false;
                if(board[i][j] != '.')
                    seenRow.insert(board[i][j]);
                
                if(seenCol.count(board[j][i]))
                    return false;
                if(board[j][i] != '.')
                    seenCol.insert(board[j][i]);
            }
        }
        for(int i = 0; i<9; i+=3) {
            for(int j = 0; j<9; j+=3) {
                unordered_set<char> seen;
                for(int k = i; k<i+3; k++) {
                    for(int l = j; l<j+3; l++) {
                        if(seen.count(board[k][l])) 
                            return false;
                        if(board[k][l] != '.')
                            seen.insert(board[k][l]);
                    }
                }
            }
        }
        return true;
    }
};