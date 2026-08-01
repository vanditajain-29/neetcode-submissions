class Solution {
public:
    string longestPalindrome(string s) {
        int idx=0;
        int len=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            //odd idx
            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                if (r-l+1>len){
                    idx=l;
                    len=r-l+1;
                }
                l--; r++;
            }

            //even len palindrome
            l=i;
            r=i+1;
            while(l>=0 && r<n && s[l]==s[r]){
                if (r-l+1>len){
                    idx=l;
                    len=r-l+1;
                }
                l--; r++;
            }         
        }

        return (s.substr(idx,len));
    }
};
