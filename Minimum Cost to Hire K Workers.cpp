bool cmp(pair<int,double>& a, pair<int,double>& b){
    return a.first < b.first;
}
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        priority_queue<double> pq;
        vector<pair<int, double>> worker(quality.size());
        for(int i = 0; i < quality.size(); i++){
            double ratio = (double) wage[i]/quality[i];
            worker[i] = {quality[i], ratio};
            pq.push(ratio);
        }
        sort(worker.begin(), worker.end(), cmp);
        double ans = DBL_MAX;
        while(pq.size() >= k){
            double ratio = pq.top(), temp = 0;
            pq.pop();
            int cnt = k, i = 0;
            while(cnt){
                if(worker[i].second <= ratio){
                    cnt--;
                    // cout<<worker[i].first<<" "<<temp<<endl;
                    temp += worker[i].first * ratio;
                    // cout<<ratio<<" "<<worker[i].second<<" "<<temp<<endl;
                }
                i++;
            }
            cout<<endl;
            ans = min(ans, temp);
        }
        return ans;
    }
};
