class Solution {
public:
    int numDecodings(string s) {
        if (s[0]=='0') return 0;
        int n=s.length();
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;
        for(int i=2; i<=n; i++){
            if(s[i-1]!='0'){
                dp[i]+=dp[i-1];
            }
            int twodig= (s[i-2]-'0')*10 + (s[i-1]-'0');
            if(twodig>=10 && twodig<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};