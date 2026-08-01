class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res=nums[0];
        int curmin=1;
        int curmax=1;
        for(int num:nums){
            int temp=curmax*num;
            curmax=max(max(curmax*num,curmin*num),num);
            curmin=min(min(temp,curmin*num),num);
            res=max(curmax,res);
        }
        return res;
    }
};
