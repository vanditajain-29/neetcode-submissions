class Solution {
public:
    vector<vector<int>> res;
    
    void dfs(vector<int>&nums, int target, vector<int>&cur, int i){
        if(target==0) {
            res.push_back(cur);
            return;
        }

        if(target<0 || i>=nums.size()) return;

        cur.push_back(nums[i]);
        dfs(nums,target-nums[i], cur, i);
        cur.pop_back();
        dfs(nums,target,cur,i+1);
    }
    
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> cur;
        dfs(nums, target, cur, 0);
        return res;
    }
};
