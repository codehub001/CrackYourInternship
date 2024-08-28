class Solution {
public:
    int count = 1;
    int solve(vector<vector<int>>& grid, pair<int,int> s, pair<int,int>& e, int steps){
        // cout<<steps<<" ";
        if(s == e) return count == steps;
        if(s.first >= grid.size() || s.second >= grid[0].size() || s.first < 0 || s.second < 0) return 0;
        if(grid[s.first][s.second] == -1) return 0;
        int ans = 0;
        grid[s.first][s.second] = -1;
        ans += solve(grid, make_pair(s.first+1, s.second), e, steps+1);
        ans += solve(grid, make_pair(s.first-1, s.second), e, steps+1);
        ans += solve(grid, make_pair(s.first, s.second+1), e, steps+1);
        ans += solve(grid, make_pair(s.first, s.second-1), e, steps+1);
        grid[s.first][s.second] = 0;
        return ans;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        pair<int,int> s, e;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    s = make_pair(i, j);
                }
                else if(grid[i][j] == 2){
                    e = make_pair(i, j);
                }
                else if(grid[i][j] == 0) count++;
            }
        }
        // cout<<count<<endl;
        return solve(grid, s, e, 0);
    }
};
