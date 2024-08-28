class Solution {
public:
    bool solve(vector<vector<char>>& board, int i, int j, string& word, int k){
        if(k >= word.size()){
            return true;
        }
        if(i >= board.size() || j >= board[0].size()){
            return false;
        }
        if(board[i][j] == word[k]){
            board[i][j] = '1';
            bool ans = solve(board, i, j+1, word, k+1) || solve(board, i+1, j, word, k+1) || solve(board, i-1, j, word, k+1) || solve(board, i, j-1, word, k+1);
            board[i][j] = word[k];
            return ans;
        }
        else{
            return false;
        }
    }
    bool exist(vector<vector<char>>& board, string word) {

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(solve(board, i, j, word, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};
