class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int k) {
        int i = 0, j = 0, siz = 0, spaces = 0, extr = 0;
        vector<string> ans;
        while(j < words.size()){
            if(!siz) siz = words[j++].size();
            else if(siz + 1 + words[j].size() <= k) siz += words[j++].size()+1;
            else{
                string temp = "";
                if( i + 1 == j){
                    temp += words[i++];
                    while(temp.length() != k) temp.push_back(' ');
                }
                else{
                    spaces = k - siz;
                    extr = spaces % (j-i-1);
                    spaces = spaces / (j-i-1);

                    while(i < j-1){
                        temp += words[i++];
                        string temp2(spaces+1, ' ');
                        temp += temp2;
                        if(extr) extr--, temp += " ";
                    }
                    temp += words[i++];
                }
                ans.push_back(temp);
                siz = 0;
            }
        }
        string temp = "";
        if(i < words.size()){
            temp += words[i++];
            while(i < words.size()){
                temp += " ";
                temp += words[i++];
            }
        }
        else{
            string temp2 = ans.back();
            for(int l = 0; l < temp2.size();){
                if(temp2[l] != ' ') temp.push_back(temp2[l++]);
                else{
                    temp.push_back(temp2[l++]);
                    while(l < temp2.size() && temp2[l] != ' ') l++;
                }
            }
            ans.pop_back();
        }
        while(temp.length() != k) temp.push_back(' ');
        ans.push_back(temp);
        return ans;
    }
};
