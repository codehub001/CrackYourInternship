class disJoinSet{
    vector<int> parent, rank;
public:
    disJoinSet(int n){
        parent.resize(n);
        rank.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findParent(int n){
        if(parent[n] == n) return n;
        return parent[n] = findParent(parent[n]);
    }
    void unite(int x, int y){
        x = findParent(x);
        y = findParent(y);
        if(x != y){
            if(rank[x] > rank[y]) parent[y] = x; 
            else if(rank[x] < rank[y]) parent[x] = y;
            else{
                rank[x]++;
                parent[y] = x;
            }
        }
    }
    int diffNet(){
        unordered_set<int> s;
        for(int i = 0; i < parent.size(); i++){
            s.insert(findParent(i));
        }
        return s.size();
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        disJoinSet ds(n);
        for(auto& conn:connections){
            ds.unite(conn[0], conn[1]);
        }
        return ds.diffNet()-1;
    }
};
