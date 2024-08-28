class Solution {
public:
    bool isSafe(vector<string> &board, int row, int col){
        // Check for up 
        int i = row, j = col;
        while(j >= 0){
            if(board[i][j] == 'Q')
                return false;
            j--;
        }

        // Check for upper left diagonal
        i = row, j = col;
        while(i >= 0 && j >= 0){
            if(board[i][j] == 'Q')
                return false;
            i--;
            j--;
        }

        // Check for lower left diagonal
        i = row, j = col;
        while(i < board.size() && j >= 0){
            if(board[i][j] == 'Q')
                return false;
            i++;
            j--;
        }
        return true;
    }

    void solve(vector<string> &board, int col, int n, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col)){
                board[row][col] = 'Q';
                solve(board, col + 1, n, ans);
                board[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(board, 0, n, ans);
        return ans;
    }
};
