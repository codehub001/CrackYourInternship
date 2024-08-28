class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<string> q;
        unordered_map<string, bool> visited;
        unordered_map<string, bool> wordlist;
        for(auto& i : wordList) wordlist[i] = true;
        if(endWord == beginWord) return 1;
        q.push(beginWord);
        visited[beginWord] = true;
        int ans = 2;
        while(!q.empty()){
            int n = q.size();
            for(int k = 0; k < n; k++){
                string word = q.front();
                q.pop();
                for(int i = 0; i < word.size(); i++){
                    string temp = word;
                    for(int c = 0; c < 26; c++){
                        if(word[i] == c) continue;
                        temp[i] = 'a' + c;
                        if(wordlist[temp] && !visited[temp]){
                            if(temp == endWord) return ans;
                            visited[temp] = true;
                            q.push(temp);
                        }
                    }
                }
            }
            ans++;
        }
        return 0;
    }
};
