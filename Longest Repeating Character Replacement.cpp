class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int ans = 0, maxi_freq = 0; // Will Store maximum frequency in the range.
        int i = 0, j = 0;
        while(j < s.length()){
            freq[s[j]-'A']++;
            maxi_freq = max(maxi_freq, freq[s[j]-'A']);
            if(j-i+1 - maxi_freq > k){
                freq[s[i]-'A']--;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
