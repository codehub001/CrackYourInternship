class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp(board.size(), vector<int>(board[0].size(), 0));

        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(board[i][j]){
                    if(i-1 >= 0 && j-1 >= 0){
                        temp[i-1][j-1]++;
                    }
                    if(i-1 >= 0){
                        temp[i-1][j]++;
                    }
                    if(i-1 >= 0 && j+1 < board[0].size()){
                        temp[i-1][j+1]++;
                    }
                    if(j-1 >= 0){
                        temp[i][j-1]++;
                    }
                    if(j+1 < board[0].size()){
                        temp[i][j+1]++;     
                    }
                    if(i+1 < board.size()){
                        if(j-1 >= 0){
                            temp[i+1][j-1]++;
                        }
                        temp[i+1][j]++;
                        if(j+1 < board[0].size()){
                            temp[i+1][j+1]++;
                        }
                    }
                }
            }
        }
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                if(temp[i][j] < 2 || temp[i][j] > 3){
                    board[i][j] = 0;
                }
                else if(temp[i][j] == 3){
                    board[i][j] = 1;
                }
            }
        }
    }
};
