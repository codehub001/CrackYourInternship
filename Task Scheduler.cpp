class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;
        priority_queue<int> pq;

        for(auto i : tasks){
            mp[i]++;
        }
        for(auto i : mp){
            pq.push(i.second);
        }
        int ans = 0;
        while(pq.size() > n+1){
            cout<<0;
            ans += n+1;
            vector<int> arr;
            for(int i = 0; i <= n; i++){
                int temp = pq.top();
                pq.pop();
                if(temp > 1){
                    arr.push_back(temp-1);
                }
            }
            for(int i:arr){
                pq.push(i);
            }
        }
        if(pq.size()){
            ans += (n+1)*(pq.top()-1);
            int temp2 = pq.top();
            cout<<temp2;
            while(pq.size()){
                int temp = pq.top();
                if(temp >= temp2){
                    ans++;
                }
                else{
                    break;
                }
                pq.pop();
            }
        }
        return ans;

    }
};
