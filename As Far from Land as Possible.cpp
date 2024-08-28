class Solution {
    int o, p;
    bool isGood(int x, int y, vector<vector<int>>& grid){
        if(x >= o || x < 0 || y >= p || y < 0 || grid[x][y]) return false;
        grid[x][y] = 1;
        return true;
    }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int distance = 0;
        o = grid.size(), p = grid[0].size();
        queue<pair<int,int>> q;
        for(int i = 0; i < o; i++){
            for(int j = 0; j < p; j++){
                if(grid[i][j]) q.push({i, j});
            }
        }
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto land = q.front();
                q.pop();
                if(isGood(land.first + 1, land.second, grid)) q.push({land.first + 1, land.second});
                if(isGood(land.first, land.second + 1, grid)) q.push({land.first, land.second + 1});
                if(isGood(land.first - 1, land.second, grid)) q.push({land.first - 1, land.second});
                if(isGood(land.first, land.second - 1, grid)) q.push({land.first, land.second - 1});
            }
            if(!q.empty()) distance++;
        }
        return distance == 0 ? -1 : distance;
    }
};
