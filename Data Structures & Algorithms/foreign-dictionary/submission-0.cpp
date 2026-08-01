class Solution {
public:
unordered_map<char, unordered_set<char>> adj;

    string foreignDictionary(vector<string>& words) {
        
        for (const auto& word: words){
            for (char ch:word){
                adj[ch];
            }
        }
        for (int i=0; i<words.size()-1; i++){
            string w1=words[i];
            string w2=words[i+1];
            int minlen=min(w1.length(),w2.length());
            if (w1.length()>w2.length() && w1.substr(0,minlen)==w2.substr(0,minlen)){
                return "";
            }
            for(int j=0; j<minlen; j++){
                if(w1[j]!=w2[j]){
                    adj[w1[j]].insert(w2[j]);
                    break;
                }
            }
        }

        string res="";
        unordered_map<char,int> vis;

        for(const auto& p: adj){
            char ch= p.first;
            if(vis[ch]==0){
                if (dfs(ch, vis, res)){
                    return "";
                }
            }
        }

        reverse(res.begin(), res.end());
        return res;        
    }

    bool dfs(char c, unordered_map<char, int> &visited, string &res){
        if (visited[c]==1) return true;
        if (visited[c]==2) return false;
        
        visited[c]=1;

        for(char next: adj[c]){
            if (dfs(next, visited, res)){
                return true;
            }
        }

        res+=c;
        visited[c]=2;
        return false;


    }

};
