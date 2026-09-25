class Solution {
public:

    bool isSafe(int row, int col, vector<vector<char>>& board, char ch) {

        for (int i = 0; i < 9; i++) {

            if (i != col && board[row][i] == ch)
                return false;

            if (i != row && board[i][col] == ch)
                return false;

            int r = 3 * (row / 3) + i / 3;
            int c = 3 * (col / 3) + i % 3;

            if ((r != row || c != col) && board[r][c] == ch)
                return false;
        }

        return true;
    }
        
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){

                // cell is filled
                if(board[i][j] != '.'){
                    if(!isSafe(i,j,board, board[i][j])){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};