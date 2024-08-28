class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> freq;
        for(auto& c:s) freq[c]++;
        priority_queue<pair<int, char>> pq;
        for(auto& i:freq) pq.push(make_pair(i.second, i.first));
        string ans;
        while(pq.size() >= 2){
            pair<int,char> first = pq.top();
            pq.pop();
            pair<int,char> second = pq.top();
            pq.pop();
            ans.push_back(first.second);
            ans.push_back(second.second);
            first.first--;
            second.first--;
            if(first.first) pq.push(first);
            if(second.first) pq.push(second);
        }
        if(!pq.empty()){
            if(pq.top().first != 1) return "";
            ans.push_back(pq.top().second);
        }
        return ans;

    }
};
