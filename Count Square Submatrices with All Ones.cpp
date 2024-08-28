class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int count = 0, ans = 0;
        for(int i = 0; i < matrix.size(); i++){
            count = 0;
            for(int j = 0; j < matrix[0].size(); j++){
                count += matrix[i][j];
                matrix[i][j] = count;
                if(i > 0) matrix[i][j] += matrix[i-1][j];
            }
        }
        
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[0].size(); j++){
                for(int side = 0; i + side < matrix.size() && side + j < matrix[0].size(); side++){
                    count = matrix[i+side][j+side];      
                    if(i > 0) count -= matrix[i-1][j+side];
                    if(j > 0) count -= matrix[i+side][j-1];
                    if(i > 0 && j > 0) count += matrix[i-1][j-1];
                    if(count == (side+1)*(side+1)) ans++;
                }
            }
        }
        return ans;
    }
};
