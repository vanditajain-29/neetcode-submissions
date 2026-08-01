class Solution {
public:
    bool canJump(vector<int>& nums) {
        int final=nums.size()-1;
        for(int idx=nums.size()-2; idx>=0; idx--){
            if (idx+nums[idx]>=final){
                final=idx;
            }
        }
        return final==0;
    }
};
