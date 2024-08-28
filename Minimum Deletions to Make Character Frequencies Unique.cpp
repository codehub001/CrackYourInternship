class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);

        for(int i=0; i<s.length(); i++){
            int temp = s[i] - 'a';
            freq[temp]++;
        }

        sort(freq.begin(), freq.end());

        int ans = 0;
        int size = 24;
        while(size+1){
            if(freq[size] == 0){
                size--;
                continue;
            }

            if(freq[size] < freq[size+1]){
                size--;
                continue;
            }
            else{
                freq[size]--;
                ans++;
            }
        }
        return ans;
    }
};
