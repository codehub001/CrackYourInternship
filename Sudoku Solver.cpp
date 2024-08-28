class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int i, int j, char c){
        for(int x = 0; x < 9; x++){
            if(board[x][j] == c){
                return false;
            }
            if(board[i][x] == c){
                return false;
            }
            if(board[i/3*3 + x/3][j/3*3 + x%3] == c){
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board, int i, int j){
        if(i >= 9){
            return true;
        }
        if(j >= 9){
            return solve(board, i+1, 0);
        }
        if(board[i][j] != '.'){
            return solve(board, i, j+1);
        }
        for(char c = '1'; c <= '9'; c++){
            if(isSafe(board, i, j, c)){
                board[i][j] = c;
                bool poss = solve(board, i, j+1);
                if(poss){
                    return true;
                }
                else{
                    board[i][j] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool ans = solve(board, 0, 0);
    }
};
