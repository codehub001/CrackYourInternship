class disJointSet{
    vector<int> parent, rank;
    public:
    disJointSet(int n){
        parent.resize(n+1);
        rank.resize(n+1, 1);
        for(int i = 0; i <= n; i++){
            parent[i] = i;
        }
    }
    int findParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    void unite(int u, int v){
        u = findParent(u);
        v = findParent(v);

        if(u == v) return;
        if(rank[u] > rank[v]) parent[v] = u;
        else if(rank[u] < rank[v]) parent[u] = v;
        else{
            parent[u] = v;
            rank[v]++;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // equals to number of nodes as one edge is extra
        disJointSet ds(n);
        vector<int> ans(2);

        for(auto i:edges){
            if(ds.findParent(i[0]) != ds.findParent(i[1])){
                ds.unite(i[0], i[1]);
            }
            else{
                ans[0] = i[0];
                ans[1] = i[1];
            }
        }
        return ans;
    }
};
