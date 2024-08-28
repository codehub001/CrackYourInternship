class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int> pq;
        int ans = 0;
        int pos = startFuel;
        if(pos >= target) return ans;
        for(int i = 0; 1;){
            if(pos >= target) return ans;
            while(i < stations.size() && pos >= stations[i][0]){
                pq.push(stations[i++][1]);
            }
            if(pq.empty()) return -1;
            pos += pq.top();
            pq.pop();
            ans++;
        }
        return -1;
    }
};
