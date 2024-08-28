class Solution {
public:
    void dfsPaint(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>>& q){
        if(max(i, j) >= grid.size() || min(i, j) < 0 || grid[i][j] != 1) return;
        q.push(make_pair(i, j));
        grid[i][j] = 2;
        dfsPaint(i+1, j, grid, q);
        dfsPaint(i, j+1, grid, q);
        dfsPaint(i-1, j, grid, q);
        dfsPaint(i, j-1, grid, q);
    }
    void expand(int i, int j, vector<vector<int>>& grid, queue<pair<int,int>>& q, int val){
        if(max(i, j) >= grid.size() || min(i, j) < 0 || grid[i][j] > 1) return;
        if(!grid[i][j]) grid[i][j] = val;
        q.push(make_pair(i, j));
    }
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j]){
                    dfsPaint(i, j, grid, q);
                    i = grid.size();
                    j = grid[0].size();
                }
            }
        }
        int ans = 0;
        while(true){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto xy = q.front();
                q.pop();
                if(grid[xy.first][xy.second] == 1) return ans-1;
                expand(xy.first+1, xy.second, grid, q, ans + 3);
                expand(xy.first, xy.second+1, grid, q, ans + 3);
                expand(xy.first-1, xy.second, grid, q, ans + 3);
                expand(xy.first, xy.second-1, grid, q, ans + 3);
            }
            ans++;
        }
        return ans;
    }
};
