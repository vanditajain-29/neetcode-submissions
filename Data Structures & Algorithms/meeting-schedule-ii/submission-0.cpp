/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> st;
        vector<int> e;
        for(auto& interval : intervals){
            st.push_back(interval.start);
            e.push_back(interval.end);
        }
        sort(st.begin(),st.end());
        sort(e.begin(), e.end());
        int n=st.size();
        int i=0, j=0;
        int count=0;
        int maxc=0;
        while(i<n){
            if(st[i]<e[j]){
                count++;
                i++;
            }
            else{
                count--;
                j++;
            }
            maxc=max(maxc,count);
        }
        return maxc;
     
    }
};
