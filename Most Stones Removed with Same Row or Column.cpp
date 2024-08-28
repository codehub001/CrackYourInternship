class Solution {
    int islands = 0;
    unordered_map<int,int> parent;
    int findParent(int x){
        if(!parent.count(x)) parent[x] = x, islands++;
        if(parent[x] != x) parent[x] = findParent(parent[x]);
        return parent[x];
    }
    void unite(int x, int y){
        x = findParent(x), y = findParent(y);
        if(x != y) parent[x] = y, islands--;
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        for(auto& stone:stones){
            unite(stone[0], ~stone[1]);
        }
        return stones.size() - islands;
    }
};
