class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> prev;

        for(int i=0; i<n; i++){
            int diff=target-nums[i];
            if (prev.find(diff)!=prev.end()){
                return {prev[diff],i};
            }
            prev.insert({nums[i],i});
        }
        return {};
    }
};
