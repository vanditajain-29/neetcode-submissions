class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int maxlen=0;
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        for(string& word : wordDict){
            maxlen=max(maxlen, (int)word.length());
        }
        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i = 1; i <= n; i++) {
            for(int j = i - 1; j >= 0 && (i - j) <= maxlen; j--) {
                if(dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
