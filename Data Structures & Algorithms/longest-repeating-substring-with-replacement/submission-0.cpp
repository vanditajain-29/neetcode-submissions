class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> hash(26,0);
        int l=0; int r=0;
        int n=s.length();
        int maxfreq=0;
        int maxlen=0;

        while (r<n){
            hash[s[r]-'A']++;
            maxfreq=max(hash[s[r]-'A'], maxfreq);
            int len=r-l+1;
            while(len-maxfreq>k){
                hash[s[l]-'A']--;
                maxfreq=0;
                for (int i=0; i<26; i++){
                    maxfreq=max(maxfreq, hash[i]);
                }
                l++;
                len=r-l+1;
            }
            len=r-l+1;
            if(len-maxfreq<=k){
                maxlen=max(maxlen, len);
            }
            r++;
        }
        return maxlen;
    }
};
