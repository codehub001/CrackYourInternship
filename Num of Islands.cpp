class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int i, int j){
        visited[i][j] = true;
        if(i < grid.size()-1 && !visited[i+1][j] && grid[i+1][j] == '1') dfs(grid, visited, i+1, j);
        if(i > 0 && !visited[i-1][j] && grid[i-1][j] == '1') dfs(grid, visited, i-1, j);
        if(j < grid[0].size()-1 && !visited[i][j+1] && grid[i][j+1] == '1') dfs(grid, visited, i, j+1);
        if(j > 0 && !visited[i][j-1] && grid[i][j-1] == '1') dfs(grid, visited, i, j-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        int ans = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }
        return ans;
    }
};
