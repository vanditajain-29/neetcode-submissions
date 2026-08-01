class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m=t.size();
        if(m==0) return "";
        vector<int> hash(256,0);
        for (int i=0; i<m; i++) hash[t[i]]++;
        int l=0; int r=0;
        int minlen=1e9;
        int count=0;
        int start=-1;
        while(r<n){
            if(hash[s[r]]>0) count++;
            hash[s[r]]--;
            while (count==m){
                if (r-l+1<minlen){
                    minlen=r-l+1;
                    start=l;
                }
                hash[s[l]]++;
                if (hash[s[l]]>0) count--;
                l++;
            }
            r++;
        }
        return start == -1 ? "" : s.substr(start, minlen);
    }
};
