class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;
        long long i = 0, ans;
        pq.push(1);
        while(i < n){
            i++;
            ans = pq.top();
            pq.pop();
            long long temp = ans * 2;
            if(temp <= INT_MAX && !mp[temp]){
                pq.push(ans * 2);
                mp[temp]++;
            }
            temp = ans * 3;
            if(temp <= INT_MAX && !mp[temp]){
                pq.push(temp);
                mp[temp]++;
            }
            temp = ans * 5;
            if(temp <= INT_MAX && !mp[temp]){
                pq.push(temp);
                mp[temp]++;
            }
        }
        cout<<ans<<endl;
        return ans;
    }
};
