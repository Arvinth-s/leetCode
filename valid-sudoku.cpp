//OM NAMO NARYANA
//https://leetcode.com/problems/valid-sudoku/submissions/


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        assert(board.size()==9);
        bool col[9][9], row[9][9], block[9][9];
        memset(col, false, sizeof(col));
        memset(row, false, sizeof(row));
        memset(block, false, sizeof(block));
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j]!='.'){
                    int val = int(board[i][j]-'0')-1;
                    if(row[i][val] ||col[j][val] || block[int(i/3)*3 + j/3][val])return false;
                    row[i][val] = col[j][val] = block[int(i/3)*3 + j/3][val] = true;
                }
            }
        }
        return true;
    }
};