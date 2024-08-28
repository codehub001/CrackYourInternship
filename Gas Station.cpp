class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ans = 0, tank = 0;
        int total1 = 0, total2 = 0;
        for(int i = 0; i < gas.size(); i++){
            total1 += gas[i];
            total2 += cost[i];
            tank += gas[i] - cost[i];
            if(tank < 0){
                tank = 0;
                ans = i+1;
            }
        }
        ans %= gas.size();
        return total1 >= total2 ? ans : -1;
    }
};
